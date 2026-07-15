//******************************************//
void channelFlow::fieldvariable()
{
//dimension assignment parameterr
lenght =1;
height =1;
t_node_x=2;
t_node_y=97;
del_x = lenght/t_node_y;
del_y = height/t_node_y;
cout<<del_x<<"\n"<<del_y<<"\n";
//field variable parameter
u_tau = 1;
mu    =0.002531;         // Re_t=395,  rho=1,  u_tau=1
rho=1;

//Boundary condition
u_wall =0;
v_wall =0;			// for wall condition
k_wall =0;
e_grad_y_wall=0;
//Centerline 
float u_centre_grad=0;
float e_centre=0;
float k_centre_grad=0;
//initial condition
k_tur_init=0.4;  		 // using dns data for initialization
e_energy_init=0.01;     // using dns data for initialization
u_init=0.5;              // using dns data for initialization
p_init=2;                //using dns data for initialization
//inlet
float u_inlet_x=20;
k_grad_x=0;			// inlet and outlet condition
e_grad_x=0;
p_grad_x=-1;
//outlet
float u_outlet_x_grad=0;


//allocating space for calculated variable

/* I am using sttagered grid to stored field variable , so we are not storing velocity and scalar parameter at same location, also i am using ghost cell so that we can satisfy our boundary condition because we are not storing scalar field at wall, we are storing at center.
hence, can find the size of matrixs dimension as
if t_n_x=m and t_n_y=n
total node in x direction = 2*m + 1 + 2  [2 for ghost cell parameter 1+1]
total node in y direction = 2*n + 1 + 2  [2 for ghost cell parameter 1+1]
 
*/
T_node_x=2*t_node_x +1 +2;
T_node_y=2*t_node_y +1 +2;



//cout<<T_node_x;



p_u_field = new float*[T_node_y] ;
p_u_field_error = new float*[T_node_y] ;
mu_tur    = new float*[T_node_y] ;
k_tur     = new float*[T_node_y] ;
e_energy  = new float*[T_node_y] ;
prod_k    = new float*[T_node_y] ;		
t_diff    = new float*[T_node_y] ;
v_diff    = new float*[T_node_y] ;
uv_stress        = new float*[T_node_y] ;


for(int i=0; i<T_node_y;i++)
{

p_u_field[i] = new float [T_node_x] ;
p_u_field_error[i] = new float [T_node_x] ;
mu_tur[i]    = new float [T_node_x] ;
k_tur[i]     = new float [T_node_x] ;
e_energy[i]  = new float [T_node_x] ;
prod_k[i]    = new float [T_node_x] ;		
t_diff[i]    = new float [T_node_x] ;
v_diff[i]    = new float [T_node_x] ;
uv_stress[i]        = new float [T_node_x] ;

}


//assign all default value 0 after this we will set initial and boundary condition 
for(int j=0;j<T_node_y;j++)
{
	for(int i=0;i<T_node_x;i++)

	{
	p_u_field[j][i] =0;
	p_u_field_error[j][i] =0 ;
	mu_tur[j][i]    = mu ;
	k_tur[j][i]     = k_tur_init ;
	e_energy[j][i]  = e_energy_init ;
	prod_k[j][i]    = 0 ;		
	t_diff[j][i]    = 0 ;
	v_diff[j][i]    = 0 ;
	uv_stress[j][i]    = 0 ;


	}


}

// ************************************************************************************* //
 
ifstream finp;
ifstream finu;
ifstream fine;
ifstream finpr;

finp.open("production.txt");
finu.open("u_dns.txt");
fine.open("epsilon.txt");
finpr.open("p_dns.txt");

/*
float d1 , d2,d3,d4;
finpr>>d1>>d2;
cout<<d1<<"\n"<<d2<<"\n";
*/
float pr[t_node_x], e[t_node_y], u[t_node_y],p[t_node_y];
float pr1,e1,u1,p1;
for(int i=0; i<t_node_x;i++)
{finpr>>pr1;
 pr[i]=pr1; }

for(int i=0; i<t_node_y ; i++)
{
 
finu>>u1;
 u[i]=u1;
finp>>p1;
 p[i]=p1;
fine>>e1;
 e[i]=e1;

}

/*for(int i=0; i<194; i++)
{cout<<p[i]<<"\n";} */

// set the field initial value in internal domain

int i_p,i_u,i_e;
i_p=0; i_u=0;i_e=0;

for(int j=2; j<(T_node_y-2); j++)
{
  if((j%2)==0)
	{//cout<<"hello j="<<j<<"\n";
	
	for(int i=2; i<(T_node_x-2); i++)
		{	/*if(j==2)
			cout<<"hello i="<<i<<"\n";*/

		if(i%2==0)
			{
			 p_u_field[j][i] = pr[i_p];      // set initial uniform pressure 1 scalar field
			 i_p =i_p+1;   // take care for initialization with dns data
			 p_u_field_error[j][i]=0;
			 k_tur[j][i]=k_tur_init;
			 e_energy[j][i]=e[i_e];
			 prod_k[j][i]=p[i_e];
			}        
		
		else
			{

				p_u_field[j][i] = u[i_u];

			}	// set initial u_velocity uniform 0.5
		}
		i_p=0;
		i_u= i_u +1;    // take care for initialization with dns data
		i_e= i_e +1;
		 
	}
  else
	{
	for(int i=2; i<(T_node_x-2); i++)
		{
		if(i%2==0)
			{p_u_field[j][i] = 0;}        // set v velocity 0 every were in this problem
		
		else
			{p_u_field[j][i] = 0;}	// default 0 no varible at this location
		} 


	}

}



/*

// checking boundary value here
for(int j=0; j<T_node_y;j++)
{
   
	 
	for(int i=0; i<T_node_x; i++)
		{
		  cout<<p_u_field[j][i]<<"	";
		}
	cout<<"\n";
 
}


cout<<"\n\n\n\n";

*/




}

 
