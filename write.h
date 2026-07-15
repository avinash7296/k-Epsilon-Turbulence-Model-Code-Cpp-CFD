void channelFlow::write()
{
ofstream foutp;
ofstream foutu;
ofstream foute;
ofstream foutpr;
ofstream foutk;     // this is calculated using initialised data
ofstream foutvt;	   // this is calculated using initialised data
ofstream foutkd;
ofstream foutvd;
ofstream foutst;

foutp.open("Production_calculated.txt");
foutu.open("U_calculated.txt");
foute.open("Epsilon_calculated.txt");
foutpr.open("P_calculated.txt");
foutk.open("K_tur_calculated");
foutvt.open("Vt_tur_calculated");


foutkd.open("Turbulance_kinetic_diff.txt");
foutvd.open("Viscous_kinetic_diff.txt");
foutst.open("Shearstress.txt");




int i=4;
for(int j=2; j<(T_node_y-2);j++)
{
	if(j%2==0)   
 		{
		foutp<<prod_k[j][i]<<"\n";
		foute<<e_energy[j][i]<<"\n";
		foutk<<k_tur[j][i]<<"\n";
		foutvt<<(mu_tur[j][i] -mu) <<"\n";

		foutkd<<t_diff[j][i]<<"\n";
		foutvd<<v_diff[j][i]<<"\n";
		foutst<<uv_stress[j][i]<<"\n";
		}
	
}

i=3;
for(int j=2; j<(T_node_y-2);j++)
{
	if(j%2==0)   
 		{
		 foutu<<p_u_field[j][i]<<"\n";
		}
	 
 
}


int j=4;
for(i=2; i<(T_node_x-2);i++)
{
	if(i%2==0)   
 		{
		 foutpr<<p_u_field[j][i]<<"\n";
		}
	 
}

}




