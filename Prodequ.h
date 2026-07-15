//***********************************//
void channelFlow::Prodequ()

{
float temp;
float N_u,S_u;
for(int j=2; j<(T_node_y-2); j++)
	{
	  if((j%2)==0)
		{
		for(int i=2; i<(T_node_x-2); i++)
			{
			if(i%2==0)
				{ 

				  N_u= (p_u_field[j][i-1] + p_u_field[j][i-1] + p_u_field[j-2][i-1] 
											+ p_u_field[j-2][i+1])/4;

				  S_u= (p_u_field[j][i-1] + p_u_field[j][i-1] + p_u_field[j+2][i-1] 
											+ p_u_field[j+2][i+1])/4;

				  //cout<<N_u<<"	"<<S_u<<"\n\n";
				  //cout<<"diff	="<<(N_u-S_u)<<"diff_p	="<<(N_u-S_u)*(N_u-S_u)<<"\n\n"; 
				  temp=(N_u - S_u)*(N_u - S_u); 
				  prod_k[j][i]= 0.001*((mu_tur[j][i]-mu)*temp)/(del_y*del_y);
				}        
			}
			 

		}

	}

}
