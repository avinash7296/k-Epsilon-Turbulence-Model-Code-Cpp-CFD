//***********************************//
void channelFlow::Kequ()

{
float sigma_k;
sigma_k=1;
float a_p, a_n,a_s,c_n,c_s;

int count=0;
float temp,error;
int itrk=0;
while(1)
  {
	for (int j=2; j<(T_node_y-2); j++)
	{
		if(j%2==0)
		{ for(int i=2; i<(T_node_x-2); i++)
			{
				if(i%2==0)
				{
				c_n=( (mu + (mu_tur[j][i]-mu)/sigma_k) + (mu + (mu_tur[j-2][i]-mu)/sigma_k) )/2;
				c_s=( (mu + (mu_tur[j][i]-mu)/sigma_k) + (mu + (mu_tur[j+2][i]-mu)/sigma_k) )/2;
				a_n=c_n*(del_x/del_y);
				a_s=c_s*(del_x/del_y);
				a_p=a_s + a_n;
				if(a_p==0)
				{cout<<"a_p of k_tur  is zero"<<"\n"; a_p=0.000001;}
				temp=k_tur[j][i];
				k_tur[j][i]=(a_n/a_p)*k_tur[j-2][i] + (a_s/a_p)*k_tur[j+2][i] 
						+ ( prod_k[j][i]*del_x*del_y - e_energy[j][i]*del_x*del_y)/a_p ;
				//fixing parameter near the wall
				if(k_tur[j][i]<0)
				{k_tur[j][i] = -0.1*k_tur[j][i];}
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
itrk =itrk +1;
if(itrk>500)
{cout<<"i break\n";break;}
boundarySet();
if(count==((t_node_x)*t_node_y))
{break;}

// checking boundary value here
/*
for(int j=0; j<T_node_y;j++)
{
   
	 
	for(int i=0; i<T_node_x; i++)
		{
		  cout<<k_tur[j][i]<<"	";
		}
	cout<<"\n";
 
}


cout<<"\n\n\n\n";

*/
  }


}
