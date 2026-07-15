//***********************************//
void channelFlow::Modelvalue()

{
float sigma_k;
sigma_k=0.09;
float U_n,U_s;

for(int j=2; j<(T_node_y-2) ; j++)
	{
	if(j%2==0)
		{
		for(int i=2; i<(T_node_x-2); i++)

			{if(i%2==0)
				 {
				  
			//Turbulent diffusion
			t_diff[j][i]= ((mu_tur[j][i] -mu)*(k_tur[j-2][i]-k_tur[j+2][i]))/(2*del_y*sigma_k);

			//Turbulent diffusion
			v_diff[j][i]= ( mu*(k_tur[j-2][i]-k_tur[j+2][i]))/(2*del_y);

			//shear stress
			U_n=( p_u_field[j][i-1] + p_u_field[j][i+1] + p_u_field[j-2][i-1] + p_u_field[j-2][i+1] )/4 ;
			U_s=( p_u_field[j][i-1] + p_u_field[j][i+1] + p_u_field[j+2][i-1] + p_u_field[j+2][i+1] )/4 ;
			uv_stress[j][i]  =( (mu_tur[j][i] - mu)*(U_n -U_s) )/del_y ;
				}
				 
			}
	        }
	}



}
