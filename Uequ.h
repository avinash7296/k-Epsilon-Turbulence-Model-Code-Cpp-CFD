//***********************************//
void channelFlow::Uequ()

{
float a_en,a_es,a_e,c_p;
c_p=del_y/rho;

int count=0;
float temp,error;
int itru=0;
while(1)   // infinite loop 
{
for(int j=2; j<(T_node_y-2); j++)

{	 
	if(j%2==0)
		{
		for(int i=2; i<(T_node_x-2); i++)

			{if(i%2!=0)
				 {
			a_en =((mu_tur[j][i-1]+mu_tur[j][i+1]+mu_tur[j-2][i-1]+mu_tur[j-2][i+1])*del_x)/(4*del_y);
			a_es =((mu_tur[j][i-1]+mu_tur[j][i+1]+mu_tur[j+2][i-1]+mu_tur[j+2][i+1])*del_x)/(4*del_y);
			a_e  =a_en +a_es;
			//cout<<"a_en ="<<a_en<<"a_es ="<<a_es<<"\n";
			if(a_e==0)
			{cout<<"\na_e coefficient is zero\n"; a_e=0.000001;}
			temp = p_u_field[j][i] ;
			p_u_field[j][i]=(a_en/a_e)*p_u_field[j-2][i] + (a_es/a_e)*p_u_field[j+2][i] 
						+(c_p/a_e)*(p_u_field[j][i-1]-	p_u_field[j][i+1]); 

			if((p_u_field[j][i]-temp)<0)
				{error = -1*((p_u_field[j][i])-temp);}
			else
				{error= (p_u_field[j][i])-temp;}
			if(error<0.0001)
				{count = count +1;}

			
				//cout<<a_e<<"	";


				 }
			}//cout<<"\n\n\n\n";
		}


}
boundarySet();
itru=itru+1;
if(itru>1000)
{break;}
if(count==((t_node_x-1)*t_node_y))
{break;}


}


}
