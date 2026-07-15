/**********************************************************/
#include<iostream>
#include<fstream>

using namespace std;

class channelFlow
{

private:
float del_x,del_y,lenght,height;   // descretised length

int t_node_x,t_node_y,T_node_x,T_node_y ; //total node in x and y direction
 
float u_tau,mu,rho;         // u_t skin velocity

float **p_u_field,**p_u_field_error, **mu_tur, **k_tur, **e_energy, **prod_k, **t_diff,**v_diff,**uv_stress;

float k_tur_init,e_energy_init,u_init,p_init;

float u_wall,v_wall,k_wall,e_grad_y_wall;         // this is for wall condition

float u_grad_x,k_grad_x,e_grad_x,p_grad_x;		// boundary condition for inlet and outlet

public:
void fieldvariable();
void boundarySet();
void callfunction(); 
void Mutequ();
void Uequ();
void Pequ();
void Prodequ();
void Kequ();
void Epequ();
void Modelvalue();
void write();

};
#include"fieldvariable.h"
#include"boundarySet.h"
#include"callfunction.h"
#include"Mutequ.h"
#include"Uequ.h"
#include"Pequ.h"
#include"Prodequ.h"
#include"Kequ.h"
#include"Epequ.h"
#include"Modelvalue.h"
#include"write.h"

int main()

{

channelFlow obj;
obj.fieldvariable();
obj.boundarySet();
obj.callfunction();



}
