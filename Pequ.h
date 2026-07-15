//***********************************//
void channelFlow::Pequ()

{//0

int e_i,e_j,w_i,w_j;  // to trach the index for east and west face
float a_en,a_es,a_e,a_wn,a_ws,a_w;
float c,c_p,c_w,c_e;
c = (del_y/rho);

for(int itr=0; itr<300;itr++)
{//5

	for(int j=2; j<(T_node_y-2); j++)
	 {//4
	     if(j%2==0)
		{//3
		 for(int i =2; i<(T_node_x-2);i++)
			  {//2
			    if(i%2==0)
				    {//1
		 			//index catching west and east face
					e_i=i+1 ; e_j=j;
					w_i=i-1 ; w_j=j;
					//west face coefficient
					a_wn =((mu_tur[w_j][w_i-1]+mu_tur[w_j][w_i+1]+mu_tur[w_j-2][w_i-1]
							+mu_tur[w_j-2][w_i+1])*del_x)/(4*del_y);

					a_ws =((mu_tur[w_j][w_i-1]+mu_tur[w_j][w_i+1]+mu_tur[w_j+2][w_i-1]
							+mu_tur[w_j+2][w_i+1])*del_x)/(4*del_y);
					a_w  =a_wn +a_ws;
					//east face coefficient
					a_en =((mu_tur[e_j][e_i-1]+mu_tur[e_j][e_i+1]+mu_tur[e_j-2][e_i-1]
							+mu_tur[e_j-2][e_i+1])*del_x)/(4*del_y);

					a_es =((mu_tur[e_j][e_i-1]+mu_tur[e_j][e_i+1]+mu_tur[e_j+2][e_i-1]
							+mu_tur[e_j+2][e_i+1])*del_x)/(4*del_y);
					a_e  =a_en +a_es;

					//pressure coefficient
					c_w=c/a_w;
					c_e=c/a_e;
					c_p=(c_w + c_e);
					if(c_p==0)
					{c_p=0.000001;
					cout<<"c_p is zero\n";}

					//pressure equation
					p_u_field_error[j][i]=(c_w/c_p)*p_u_field_error[j][i-2] 
								+ (c_e/c_p)*p_u_field_error[j][i+2] 
								-(1/c_p)*(p_u_field[j][i+1]-p_u_field[j][i-1]);

				    }//1
			  }//2
		}//3

	 }//4


}//5



//corrector step
for(int j=2; j<(T_node_y-2);j++) 
	{
	if(j%2==0)
		{
		for(int i=2; i<(T_node_x-2); i++)
			{if(i%2==0)
				{
				p_u_field[j][i]= p_u_field[j][i] + p_u_field_error[j][i];
				}

			else

				{
				a_en =((mu_tur[j][i-1]+mu_tur[j][i+1]+mu_tur[j-2][i-1]
					+ mu_tur[j-2][i+1])*del_x)/(4*del_y);
				a_es =((mu_tur[j][i-1]+mu_tur[j][i+1]+mu_tur[j+2][i-1]
					+mu_tur[j+2][i+1])*del_x)/(4*del_y);
				a_e  =a_en +a_es;
				if(a_e==0)
				{cout<<"\na_e coefficient is zero\n"; a_e=0.000001;}
				p_u_field[j][i] = p_u_field[j][i] 
					+ (c/a_e)*(p_u_field_error[j][i-1]-p_u_field_error[j][i+1]);

				}
			}


		}


	}

//now update boundary condition to corrected value
boundarySet();

}//0
