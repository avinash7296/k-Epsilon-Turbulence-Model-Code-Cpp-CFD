//*********************************************//
void channelFlow::boundarySet()
{
// set boundary condition hear

for(int j=0; j<T_node_y; j++)
   {
	if(j%2==0)       // u p row or u,scalar row
	{//1
	     if(j==0) //1st row   wall
		{ for(int i=0; i<T_node_x; i++)
                    {
		     if(i%2==0) // p or scalar location
			{
                        p_u_field[j][i]=0;
                        k_tur[j][i] = -k_tur[j+2][i];
                        e_energy[j][i]= e_energy[j+2][i];
			}
		     else
			{
    			p_u_field[j][i] = - p_u_field[j+2][i];
			}
			
		    }

		}

             else if(j==(T_node_y-1))  //centre line boundary condition
		{
		  for(int i=0; i<T_node_x; i++)
                    {
		     if(i%2==0) // p or scalar location
			{
                        p_u_field[j][i]=p_u_field[j-2][i];
                        k_tur[j][i] = k_tur[j-2][i];
                        e_energy[j][i]= 0.0001;
			}
		     else
			{
    			p_u_field[j][i] =  p_u_field[j-2][i];
			}
			
		    }

		}

	     
 	     else
		{
		//inlet
		p_u_field[j][0]=p_u_field[j][0+2] - p_grad_x*del_x;  //p_grad*del_x
                k_tur[j][0] = k_tur[j][0+2];
                e_energy[j][0]= e_energy[j][0+2];          //inlet
		
		p_u_field[j][1]= p_u_field[j][1+2];   // no need for this

		//outlet
		p_u_field[j][T_node_x -1]=p_u_field[j][T_node_x-3] + p_grad_x*del_x;  //p_grad*del_x
                k_tur[j][T_node_x -1] = k_tur[j][T_node_x -3];
                e_energy[j][T_node_x -1]= e_energy[j][T_node_x -3];             //inlet
		
		p_u_field[j][T_node_x -2]= p_u_field[j][T_node_x -4];

		}

	
	
	}//1

        

	//else		// v row 
        //{ v is zero so no need to manupulat boundary condition for v}

      
   }

// takcare for above top two conner u velocity
p_u_field[0][1] = - p_u_field[2][1];
p_u_field[0][T_node_x-2] = - p_u_field[2][T_node_x-2];


/*

for(int j=0; j<T_node_y;j++)
{
   
	 
	for(int i=0; i<T_node_x; i++)
		{
		 cout<<e_energy[j][i]<<"	";
		}
	cout<<"\n";
 
}

*/
	 

}
