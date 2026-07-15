//***********************************//
void channelFlow::Mutequ()

{
float mu_t;
float c_mu;
c_mu = 0.09;
float temp;
for(int j=2; j<(T_node_y-2) ; j++)
	{
	if(j%2==0)
		{
		for(int i=2; i<(T_node_x-2); i++)

			{if(i%2==0)
				 {
				 if(e_energy[j][i]==0)
				  {e_energy[j][i]=0.00001;}
				 //if(k_tur[j][i]<0)
				   //{k_tur[j][i] = 0.001;}
				 temp= c_mu*((k_tur[j][i]*k_tur[j][i])/e_energy[j][i]);
				 if(temp<0)
					{temp=-1*temp;}
				 mu_tur[j][i]= mu + temp;
				 }
			}
		}
	}



}
