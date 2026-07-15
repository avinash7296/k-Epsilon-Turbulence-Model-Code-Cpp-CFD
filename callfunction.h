//**********************//

void channelFlow::callfunction()

{

for(int k=0; k<10; k++)
{
Kequ();

Mutequ();

//for(int i=0; i<10; i++)
//{
Uequ();
//Pequ();  		// no need to solve pressure equation

Epequ();
Prodequ();
 }
/*
// checking boundary value here
for(int j=0; j<T_node_y;j++)
{
   
	 
	for(int i=0; i<T_node_x; i++)
		{
		  cout<<mu_tur[j][i]<<"	";
		}
	cout<<"\n";
 
}


cout<<"\n\n\n\n";


//}


*/
 
Modelvalue();


write();


}
 


 


