//***********************************//
void channelFlow::Epequ()

{
//hear e_energy is episilon
float sigma_e,c_e1,c_e2;
sigma_e=1.3;
c_e1=1.44;
c_e2=1.92;
float a_p, a_n,a_s,c_n,c_s;
float temp1,kt,cons;

int count=0;
float temp,error;
int itrk=0;

for(int itr=0; itr<10; itr++)
  {
	for (int j=2; j<(T_node_y-2); j++)
	{
		if(j%2==0)
		{ for(int i=2; i<(T_node_x-2); i++)
			{
				if(i%2==0)
				{
				c_n=( (mu + (mu_tur[j][i]-mu)/sigma_e) + (mu + (mu_tur[j-2][i]-mu)/sigma_e) )/2;
				c_s=( (mu + (mu_tur[j][i]-mu)/sigma_e) + (mu + (mu_tur[j+2][i]-mu)/sigma_e) )/2;
				a_n=c_n*(del_x/del_y);
				a_s=c_s*(del_x/del_y);
				a_p=a_s + a_n;
				temp1=e_energy[j][i];
				kt  =k_tur[j][i];
				cons = (c_e1*(temp1/kt)*prod_k[j][i] - c_e2*(temp1*temp1/kt))*(del_x*del_y) ;
	  			e_energy[j][i]=(a_n/a_p)*e_energy[j-2][i] + (a_s/a_p)*e_energy[j+2][i] + cons ;

				//fixing parameter near the wall
				//if(k_tur[j][i]<0)
				//{k_tur[j][i] = -0.1*k_tur[j][i];}
				if((p_u_field[j][i]-temp)<0)
				{error = -1*((p_u_field[j][i])-temp);}
				else
					{error= (p_u_field[j][i])-temp;}
				if(error<0.0001)
					{count = count +1;}

				}
			 
			}

		}

	}
boundarySet();
itrk =itrk +1;
if(itrk>1000)
{cout<<"i break\n";break;}
boundarySet();
if(count==((t_node_x)*t_node_y))
{break;}

  }


}
