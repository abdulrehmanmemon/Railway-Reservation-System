#include<iostream>
#include<fstream>
#include <string.h>
#include<stdlib.h>
#include <time.h>
#include<sstream>
#include"T_Detail.h"
#include"login.h"
#include"reser.h"
using namespace std;

string int_string(int x){
	stringstream s;
	string y;
	s<<x;
	s>>y;
	return y;
}
string float_string(float x){
	stringstream s;
	string y;
	s<<x;
	s>>y;
	return y;
}
int string_int(string x){
	stringstream s;
	int y;
	s<<x;
	s>>y;
	return y;
}
float string_float(string x){
	stringstream s;
	float y;
	s<<x;
	s>>y;
	return y;
}
string admin_password="DSA";
string time();
reser *rfptr=NULL;
T_Detail *fptr=NULL;
int PNR;
void print_train();
void del_node(int d_num);
float value(reser *rcptr,T_Detail *cptr);
int main(){
	int opt,admin_chance=0,admin_mode_opt,user_management_opt,opt1;
	string admin_pass;
	PNR=0;
	T_Detail *cptr;
	reser *rcptr,*r2cptr;
	fstream file;
	string tem;
	//pnr file opening
	file.open("pnr_number.txt",ios::in);
	getline(file,tem);
	if (tem=="\0")
    getline(file,tem);
	PNR=string_int(tem);
	file.close();
	// file (Train_detail) reading start
	file.open("Train_data.txt",ios::in);
	if(!file.fail()){
	while(!file.eof())
	{
		getline(file,tem);
		if (tem!="\0")
		{
		T_Detail *ptr;
		ptr=new T_Detail;
		ptr->t_no=string_int(tem);
		getline(file,ptr->t_name);
		getline(file,tem);
		ptr->n_o_s=string_int(tem);
		ptr->stops(); //overloading
		for(int i=0;i<ptr->n_o_s;i++){
			getline(file,ptr->stop[i]);
		}
		getline(file,tem);
		ptr->c1=string_int(tem);
		getline(file,tem);
		ptr->c1fare=string_float(tem);
		getline(file,tem);
		ptr->c2=string_int(tem);
		getline(file,tem);
		ptr->c2fare=string_float(tem);
		getline(file,tem);
		ptr->d=string_int(tem);
		getline(file,tem);
		ptr->m=string_int(tem);
		getline(file,tem);
		ptr->y=string_int(tem);
		getline(file,ptr->route);
		if (fptr==NULL)
		{
			fptr=ptr;
			ptr->nptr=NULL;
		}
			else
			{
			cptr=fptr;
			while(cptr->nptr!=NULL)
				{
					cptr=cptr->nptr;
				}
				ptr->nptr=NULL;
				cptr->nptr=ptr;
				}
	}
	}}
	file.close();
	// file (Train_detail) reading finish
	file.open("reserve.txt",ios::in);
	if(!file.fail()){
	string y;
	// file (login_user_info) reading start
		while(!file.eof())
	{
		getline(file,tem);
		if (tem!="\0")
		{
		reser *ptr=new reser;
		ptr->set_i(tem);//id
		getline(file,y);//password
		ptr->set_p(y);
		getline(file,y);
		ptr->pnr=string_int(y);//pnr
		getline(file,y);
		ptr->tno=string_int(y);//tno
		getline(file,ptr->tname);//tname
		getline(file,ptr->board);//board
		getline(file,ptr->destination);//destina
		getline(file,ptr->pname);//pname
		getline(file,y);
		ptr->age=string_int(y);//age
		getline(file,ptr->clas);//class
		getline(file,y);
		ptr->nosr=string_int(y);//nosr
		getline(file,y);
		ptr->con1=string_int(y);//con1
		getline(file,y);
		ptr->con2=string_int(y);//con2
		getline(file,y);
		ptr->con3=string_int(y);//con3
		getline(file,y);
		ptr->con1s=string_int(y);//con1s
		getline(file,y);
		ptr->con2s=string_int(y);//con2s
		getline(file,y);//con3s
		ptr->con3s=string_int(y);
		getline(file,y);
		ptr->amount=string_float(y);
		getline(file,ptr->reser_time);//amount
		if (rfptr==NULL)
		{
			rfptr=ptr;
			ptr->nptr=NULL;
		}
			else
			{
			rcptr=rfptr;
			while(rcptr->nptr!=NULL)
				{
					rcptr=rcptr->nptr;
				}
				ptr->nptr=NULL;
				rcptr->nptr=ptr;
				}
	}}}
	file.close();
	//file (login_user_info) reading end
	while(-1){
		x:
			system("COLOR f1");
			system("CLS");
			print_train();
		cout<<"\n\t\t\t..Main Menu..\n\t\t\t1. Admin Mode\n\t\t\t2. User Mode\n\t\t\t3. Exit\n\t\t\tEnter your choice: ";
		cin>>opt;
		switch(opt){
		case 1:{

			cout<<"\nEnter Admin password: ";
			cin>>admin_pass;
			while(admin_pass!=admin_password){
				cout<<"\nIncorrect Password Enter again: ";
				cin>>admin_pass;
				admin_chance++;
				if (admin_chance==2){
					cout<<"\nAlert signal System is Corrupted\n";
					exit(0);
				}
			}
			while(-1){
				y:
			cout << "\n\t\t\t --- ADMINISTRATOR MENU --- \n";
			cout << "\t\t\t1. Add Train \n";
			cout << "\t\t\t2. Remove Train\n";
			cout << "\t\t\t3. Display Train details \n";
			cout << "\t\t\t4. User Management \n";
			cout << "\t\t\t5. Diplay Passenger details \n";
			cout << "\t\t\t6. Return to Main Menu \n";
			cout << "\t\t\tEnter your choice : ";
			cin >> admin_mode_opt;
			switch(admin_mode_opt){
				case 1:
					{
					system("CLS");
					print_train();
					T_Detail *ptr=new T_Detail;
					cout << "\n--Add New details--\n";
					cout << "\nTrain no: ";
					cin >> ptr->t_no;
					cptr=fptr;
					while(cptr!=NULL)
					{
						if (ptr->t_no==cptr->t_no)
						{
						cout<<"\nTrain Number Not unique Enter again : ";
						cin>>ptr->t_no;
						cptr=fptr;
						continue;
						}
						cptr=cptr->nptr;
					}
					ptr->getDetail();
					if (fptr==NULL)
					{
						fptr=ptr;
						ptr->nptr=NULL;
					}
					else
					{
					cptr=fptr;
					while(cptr->nptr!=NULL)
					{cptr=cptr->nptr;}
					cptr->nptr=ptr;
					ptr->nptr=NULL;
					}
					}
					break;
					case 2:
						{
							int id,flag=0;
							T_Detail *cptr=fptr;
							cout<<"\nEnter the ID of Train you want to remove: ";
							cin>>id;
							while(cptr!=NULL)
							{
								if (cptr->t_no==id)
								{
									flag=1;
								}
								cptr=cptr->nptr;
							}
							if(flag==1)
							{
							del_node(id);
							cout<<"\nTrain "<< id<<" is deleted from data base\n";
							}
							else
							cout<<"\nNo train exists with this Id\n";
						}
						break;
				case 3:
					system("CLS");
					print_train();
					if (fptr==NULL)
					cout<<"\nNo DATA Entered Regarding Train use Option 1 to Add trains\n";
					else{
					cptr=fptr;
					while(cptr!=NULL)
					{
						cptr->displaydetail();
						cptr=cptr->nptr;
					}
					}
					break;
				case 4:
					{
						system("CLS");
						print_train();
						cout<<"\n\t\t\t---WELCOME TO THE USER MANAGEMENT MENU---\n";
						while(-1){
							cout << "\t\t\t1. Add details\n";
							cout << "\t\t\t2. Display details\n";
							cout << "\t\t\t3. Return to ADMINISTRATOR MENU\n";
							cout << "\t\t\t4. Return to the main menu\n";
							cout << "Enter your choice: ";
							cin>>user_management_opt;
							switch(user_management_opt){
							case 1:
								{
								while(opt!=0)
								{reser *ptr=new reser;
								ptr->get_login();
								ptr->pnr=++PNR;
								ptr->reset();
								string iD;
								rcptr=rfptr;
								while(rcptr!=NULL){
									if(ptr->get_i()==rcptr->get_i())
									{
										cout<<"\nThis ID has been already taken ENTER AGAIN\n";
										cin>>iD;
										ptr->set_i(iD);
										rcptr=rfptr;
										continue;
									}
									rcptr=rcptr->nptr;
								}
								if (rfptr==NULL)
								{
									rfptr=ptr;
									ptr->nptr=NULL;
								}
								else
								{
								rcptr=rfptr;
								while(rcptr->nptr!=NULL)
								{rcptr=rcptr->nptr;}
								rcptr->nptr=ptr;
								ptr->nptr=NULL;
								}
								cout << "Do you want to add one more record\n";
								cout << "1-Yes\n0-No\n";
								cin>>opt1;
								if (opt1==0)
								break;
								}
							}
							break;
							case 2:
								{

									if (rfptr==NULL)
									cout<<"\nNo DATA regarding Users is stored use option 1 to store\n";
									else{
									rcptr=rfptr;
									while(rcptr!=NULL)
								{
									rcptr->displayid();
									rcptr=rcptr->nptr;
								}
								}
								}
								break;
								case 4:
									{
									goto x;
									}
									break;
								case 3:
									goto y;
									break;
								}}}
							case 5:
							system("CLS");
							print_train();
							rcptr=rfptr;
							while(rcptr!=NULL){
								if (rcptr->tno!=0)
								rcptr->displayresdet();
								else if(rcptr->tno==0)
								rcptr->display_not_reser();
								rcptr=rcptr->nptr;
							}
							break;
							case 6:
							goto x;
							break;
						}

					}
				}
					break;
					//user mode
				case 2:
				{
					system("CLS");
					print_train();
					string ID,PASS;
					int flag=0,opt;
					//user identification
					identity:
						system("CLS");
						print_train();
					cout<<"\n\t\t\tEnter your ID: ";
					cin>>ID;
					cout<<"\n\t\t\tEnter your PASSWORD: ";
					cin>>PASS;
					while(-1){
					rcptr=rfptr;
					while(rcptr!=NULL){
						if (ID==rcptr->get_i() && PASS==rcptr->get_p())
						{
						flag=1;
						break;
						}
						rcptr=rcptr->nptr;
					}
					if (flag==0)
					{
						cout<<"\nYou Might have entered ID or PASSWORD wrong do want to write again or you want to register yourself: \n";
						cout<<"\nPress 1 TO reenter \nPress 2 To register user self \nYour choice: ";
						cin>>opt;
						switch(opt)
						{
						case 1:
							cout<<"\nEnter your ID: ";
							cin>>ID;
							cout<<"\nEnter your PASSWORD: ";
							cin>>PASS;
						break;
						case 2:
							system("CLS");
							print_train();
							cout<<"\n\t\t\tUSING ADMIN MODE\n";
								reser *ptr=new reser;
								ptr->get_login();
								ptr->pnr=++PNR;
								rcptr=rfptr;
								string iD;
								while(rcptr!=NULL){
									if(ptr->get_i()==rcptr->get_i())
									{
										cout<<"\nThis ID has been already taken ENTER AGAIN\n";
										cin>>iD;
										ptr->set_i(iD);
										rcptr=rfptr;
										continue;
									}
									rcptr=rcptr->nptr;
								}
								if (rfptr==NULL)
								{
									rfptr=ptr;
									ptr->nptr=NULL;
								}
								else
								{
								rcptr=rfptr;
								while(rcptr->nptr!=NULL)
								{rcptr=rcptr->nptr;}
								rcptr->nptr=ptr;
								ptr->nptr=NULL;
								}
								ptr->reset();
							cout<<"\n\t\tYou will get a registration msg soon\n";
							cout<<"\t\t\t....SMS...\n";
							cout<<"\n\t\t\tID : "<<ptr->get_i();
							cout<<"\n\t\t\tPASSWORD : "<<ptr->get_p();
							ptr->reset();
							cout<<"\n\t\t\tPress 1. Login Screen\n\t\t\tPress 2. Main menu\n ";
							cin>>opt;
							if (opt==1)
							goto identity;
							else
							goto x;
						}
						}
						else
						break;
					}
					user_menu:
					print_train();
					cout<<"\n\t\t\tUser Menu\n";
					cout<<"\n\t\t\t1. Reserve \n\t\t\t2. Cancel \n\t\t\t3. Enquiry\n\t\t\t4. Return to Main Menu\n";
					cin>>opt;
					switch(opt){
						case 1:
							{
							rcptr=rfptr;
							int flag=0,opts;
							while(rcptr!=NULL){
								if (ID==rcptr->get_i() && PASS==rcptr->get_p())
								{
									while(-1){
										train:
										cout<<"Train no:";
										cin>>rcptr->tno;
										cptr=fptr;
										while(cptr!=NULL){
											if(rcptr->tno==cptr->t_no)
											{
												flag=1;
												break;
											}
											cptr=cptr->nptr;
										}
										if (flag==0)
										{
											cout<<"\nNo train exist with this ID Reenter correct Id\n";
										}
										else if(flag==1)
										break;
									}
									flag=0;
									cptr=fptr;
									while(cptr!=NULL)
									{
										if(cptr->t_no==rcptr->tno)
										{

											//function to be called
												rcptr->tname=cptr->t_name;
												cout<<"Enter the details as follows\n";
												board:
												cout<<"\nBoarding point:";
												cin>>rcptr->board;
												//check on stops
												for (int i=0;i<cptr->n_o_s;i++){
													if (rcptr->board==cptr->stop[i])
													{
														flag=1;
														break;
													}
												}
												if (flag==0)
													{
														cout<<"\nChoose Boarding Point from the provided stops\n";
														goto board;
													}
												dest:
												cout<<"\nDestination pt:";
												cin>>rcptr->destination;
												flag=0;
												for (int i=0;i<cptr->n_o_s;i++){
													if (rcptr->destination==cptr->stop[i])
													{
														flag=1;
													}
													if (rcptr->destination==rcptr->board)
													{
														cout<<"\nBoarding and destination point can't be same Enter Again\n";
														flag=2;
														goto board;


																																					}
												}
												if (flag==0)
													{
														cout<<"\nChoose Destination Point from the provided stops\n";
														goto dest;
													}
													flag=0;
												cout<<"Enter the class f-first class s-second class:";
												cin >> rcptr->clas;
												c:
												cout<<"\nNo of seats required:";
												cin>>rcptr->nosr;

													if (rcptr->clas=="f"&&rcptr->nosr>cptr->c1&&cptr->c1>0)
													{
														cout<<"\nNot Enough seats we have  "<<cptr->c1<<"\nPress 1 If you want these seats\nPress 2 if you want to change the train\nPress 3 if you Want to change the category\nPress 4 Get back to user menu \noption: ";
														cin>>opts;
														switch(opts){
															case 1:
																{
																rcptr->nosr=cptr->c1;
															}
																break;

															case 2:
																	{

																	rcptr->reset();
																	goto train;
																}
																	break;

															case 3:
															rcptr->clas="s";
															goto c;
															break;
															case 4:
															rcptr->reset();
															goto user_menu;
															break;
														}

													}
													else if (rcptr->clas=="f"&&rcptr->nosr>cptr->c1&&cptr->c1==0)
													{
														if (cptr->c2!=0){
															cout<<"\nFirst Class seats has been reserved Completely\nPress 1 if you want to change the train\nPress 2 if you Want to change the category\nPress 3 Get back to user menu \noption: ";
															cin>>opts;
															switch(opts){
															case 1:
																	{

																	rcptr->reset();
																	goto train;
																}
																	break;

															case 2:
															rcptr->clas="s";
															goto c;
															break;
															case 3:
																rcptr->reset();
															goto user_menu;
															break;
														}
														}
														else{
															cout<<"\nThis train is completely reserved\nPress 1 if you want to change the train\nPress 2 Get back to user menu  \noption: ";
															cin>>opts;
															if (opts==1)
															{
																	rcptr->reset();
																	goto train;
																}
															else if (opts==2)
															{
															rcptr->reset();
															goto user_menu;
														}
														}
													}

													else if (rcptr->clas=="s"&&rcptr->nosr>cptr->c2&&cptr->c2>0)
													{
														cout<<"\nNot Enough seats we have  "<<cptr->c2<<"Seats available If you want these \npress 1\nPress 2 if you want to change the train\nPress 3 if you Want to change the category\nPress 4 Get back to user menu  \noption: ";
														cin>>opts;
														switch(opts){
															case 1:
														{

																rcptr->nosr=cptr->c2;
													}
																break;
															case 2:
																{

																	rcptr->reset();
																	goto train;
															}
																	break;
															case 3:
															rcptr->clas="f";
															goto c;
															break;
															case 4:
															rcptr->reset();
															goto user_menu;
															break;
														}

													}
													else if (rcptr->clas=="f"&&rcptr->nosr>cptr->c1&&cptr->c2==0)
														{
														if (cptr->c1!=0){
															cout<<"\nSecond Class seats has been reserved Completely\nPress 1 if you want to change the train\nPress 2 if you Want to change the category\nPress 3 Get back to user menu  \noption: ";
															cin>>opts;
															switch(opts){
															case 1:
																	{

																	rcptr->reset();
																	goto train;
																}
																	break;

															case 2:
															rcptr->clas="f";
															goto c;
															break;
															case 3:
															rcptr->reset();
															goto user_menu;
															break;
														}
														}
														else{
															cout<<"\nThis train is completely reserved\nPress 1 if you want to change the train\nPress 2 Get back to user menu \noption: ";
															cin>>opts;
															if (opts==1)
															{
																	rcptr->reset();
																	goto train;
																}
																else if (opts==2)
																{
                                                               rcptr->reset();
															   goto user_menu;
																}
														}
													}
												rcptr->getresdet();
												if (rcptr->clas=="f")
												cptr->c1-=rcptr->nosr;
												else if(rcptr->clas=="s")
												cptr->c2-=rcptr->nosr;
												flag=1;
												rcptr->amount=value(rcptr,cptr);
												rcptr->reser_time=time();
												rcptr->displayresdet();
										}
										if (flag==1)
										break;
										cptr=cptr->nptr;
									}
								}
								if (flag==1)
								break;
								rcptr=rcptr->nptr;
							}
						}
						cout<<"\n<)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º><)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º>\n";
						goto user_menu;
						break;
					case 2:
						{
						rcptr=rfptr;
						int flag=0;
						while(rcptr!=NULL){
							if (ID==rcptr->get_i())
							{
								if(rcptr->tno==0){
								cout<<"\nMake reservation First\n";
								cout<<"\n<)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º><)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º>\n";
								goto user_menu;
							}
								cptr=fptr;
								while(cptr!=NULL)
								{
									if (rcptr->tno==cptr->t_no)
									{
										if(rcptr->clas=="f")
										cptr->c1+=rcptr->nosr;
										else if(rcptr->clas=="s")
										cptr->c2+=rcptr->nosr;
										flag=1;
										break;
									}
								cptr=cptr->nptr;
								}
							}
							if (flag==1)
							break;
							rcptr=rcptr->nptr;
						}
						cout<<"\nReceive your amount RS : "<<rcptr->amount<<" Back ";
						rcptr->reset();
						cout<<"\n<)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º><)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º>\n";
					goto user_menu;
					}
					break;
					case 3:
						{
						system("CLS");
						print_train();
						cptr=fptr;
						while(cptr!=NULL)
						{
							cptr->displaydetail();
							cptr=cptr->nptr;
						}
						cout<<"\n<)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º><)))><¸.·´¯·.´¯·.¸¸.·´¯·.¸><(((º>\n";
						goto user_menu;
					}
					break;
					case 4:
						goto x;
						break;
				}
			}
				break;

			case 3:
				{
					file.open("Train_data.txt",ios::out);
								file.close();
								file.open("Train_data.txt",ios::app);
								cptr=fptr;
								while(cptr!=NULL)
								{
										tem=int_string(cptr->t_no);
										file<<tem;
										file<<"\n"+cptr->t_name;
										file<<"\n"+int_string(cptr->n_o_s);
										for(int i=0;i<cptr->n_o_s;i++){
											file<<"\n"+cptr->stop[i];
										}
										tem=int_string(cptr->c1);
										file<<"\n"+tem;
										tem=float_string(cptr->c1fare);
										file<<"\n"+tem;
										tem=int_string(cptr->c2);
										file<<"\n"+tem;
										tem=float_string(cptr->c2fare);
										file<<"\n"+tem;
										tem=int_string(cptr->d);
										file<<"\n"+tem;
										tem=int_string(cptr->m);
										file<<"\n"+tem;
										tem=int_string(cptr->y);
										file<<"\n"+tem;
										file<<"\n"+cptr->route+"\n";
										cptr=cptr->nptr;
								}
								file.close();

								if(rfptr!=NULL)
								{
								file.open("reserve.txt",ios::out);
								file.close();
								file.open("reserve.txt",ios::app);
								rcptr=rfptr;
								string run;
							file<<rcptr->get_i();
							while(rcptr!=NULL){
							file<<"\n"+rcptr->get_p();
							run=int_string(rcptr->pnr);
							file<<"\n"+run;
							run=int_string(rcptr->tno);
							file<<"\n"+run;
							file<<"\n"+rcptr->tname;
							file<<"\n"+rcptr->board;
							file<<"\n"+rcptr->destination;
							file<<"\n"+rcptr->pname;
							run=int_string(rcptr->age);
							file<<"\n"+run;
							file<<"\n"+rcptr->clas;
							run=int_string(rcptr->nosr);
							file<<"\n"+run;
							run=int_string(rcptr->con1);
							file<<"\n"+run;
							run=int_string(rcptr->con2);
							file<<"\n"+run;
							run=int_string(rcptr->con3);
							file<<"\n"+run;
							run=int_string(rcptr->con1s);
							file<<"\n"+run;
						    run=int_string(rcptr->con2s);
							file<<"\n"+run;
							run=int_string(rcptr->con3s);
							file<<"\n"+run;
							run=float_string(rcptr->amount);
							file<<"\n"+run;
							file<<"\n"+rcptr->reser_time;
						rcptr=rcptr->nptr;
						if(rcptr!=NULL)
						file<<"\n"+rcptr->get_i();
						}
					}
						file.close();
						file.open("pnr_number.txt",ios::out);
						file<<int_string(PNR);
						file.close();
						cout<<"\nThanks for using our service\n";
						exit(0);
					}
						break;

			}
		}
}
string time()
{
	time_t now = time(0);
   char* dt = ctime(&now);
	return dt;
}
void del_node(int d_num)
{
	 T_Detail *temp=fptr,*prev;
	if (temp!=NULL&&temp->t_no==d_num)
	{
		fptr=temp->nptr;
		free(temp);
		return;
	}
	while (temp!=NULL&&temp->t_no!=d_num)
	{
		prev=temp;
		temp=temp->nptr;
	}
	if (temp==NULL)
	return;
	prev->nptr=temp->nptr;
	free(temp);
}
float value(reser *rcptr,T_Detail *cptr){
	float amount=0;
	if(rcptr->clas=="f")
	{amount=amount+(rcptr->con1s*((cptr->c1fare)-cptr->c1fare*0.15));
	amount=amount+(rcptr->con2s*((cptr->c1fare)-cptr->c1fare*0.10));
	amount=amount+(rcptr->con3s*((cptr->c1fare)-cptr->c1fare*0.05));
	amount=amount+(cptr->c1fare*(rcptr->nosr-(rcptr->con1s+rcptr->con2s+rcptr->con3s)));
	}
	else if(rcptr->clas=="s")
	{amount=amount+(rcptr->con1s*((cptr->c2fare)-cptr->c2fare*0.15));
	amount=amount+(rcptr->con2s*((cptr->c2fare)-cptr->c2fare*0.10));
	amount=amount+(rcptr->con3s*((cptr->c2fare)-cptr->c1fare*0.05));
	amount=amount+(cptr->c2fare*(rcptr->nosr-(rcptr->con1s+rcptr->con2s+rcptr->con3s)));
	}
	return amount;
}
void print_train(){
	cout<<"\n\t\t\t\t\t~~~~~~^~~~~~RAILWAY RESERVATION SYSTEM~~~~~~^~~~~~\n";
	cout<<"\t\t\t                 _-====-__-======-__-========-_____-============-__\n";
	cout<<"\t\t\t               _(                                                 _)\n";
	cout<<"\t\t\t            OO(           _/_ _  _  _/_   _/_ _  _  _/_           )_\n";
	cout<<"\t\t\t           0  (_          (__(_)(_) (__   (__(_)(_) (__            _)\n";
	cout<<"\t\t\t         o0     (_                                                _)\n";
	cout<<"\t\t\t        o         '=-___-===-_____-========-___________-===-dwb-='\n";
	cout<<"\t\t\t      .o                                _________\n";
	cout<<"\t\t\t     . ______          ______________  |         |      _____\n";
	cout<<"\t\t\t   _()_||__|| ________ |            |  |_________|   __||___||__\n";
	cout<<"\t\t\t  (BNSF 1995| |      | |            | __Y______00_| |_         _|\n";
	cout<<"\t\t\t /-OO----OO''=''OO--OO''=''OO--------OO''=''OO-------OO''=''OO-------OO''=P\n";
	cout<<"\t\t\t###########################################################################";
	cout<<"\n\n\n";
}
