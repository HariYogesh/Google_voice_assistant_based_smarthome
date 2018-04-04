
#ifndef CLOBOUS_H
#define CLOBOUS_H



int gps_update(char *lat,char *lon,char* speed)
{

char responsex[20];
char buff[80];
sprintf(buff,"http://api.clobous.com/%s/track/?lat=%s&long=%s&speed=%s",cloudid,lat,lon,speed);

#if(INTERNET==1)

wifi_http(buff,responsex);
#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

if(compare(responsex,"{success}"))
{

return 1;

}
else
return 0;



}




int data_updatex(char *name,int val)
{
char responsex[20];
char buff[80];
sprintf(buff,"http://api.clobous.com/%s/data/update?%s=%d",cloudid,name,val);

#if(INTERNET==1)

wifi_http(buff,responsex);
#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

if(compare(responsex,"{success}"))
{

return 1;

}
else
return 0;

}

int data_update(char *name,char *val)
{
char responsex[20];
char buff[80];
sprintf(buff,"http://api.clobous.com/%s/data/update?%s=%s",cloudid,name,val);

#if(INTERNET==1)

wifi_http(buff,responsex);
#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

if(compare(responsex,"{success}"))
{

return 1;

}
else
return 0;

}




int data_retrievex(char *name)
{
char responsex[20];
char buff[80];
char resultx[10];

sprintf(buff,"http://api.clobous.com/%s/data/retrieve?%s",cloudid,name);
#if(INTERNET==1)

wifi_http(buff,responsex);

#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

		jsonparser(responsex,name,resultx);


        return atoi(resultx);

}



void data_retrieve(char *name,char *valuex)
{
char responsex[20];
char buff[80];
char resultx[10];

sprintf(buff,"http://api.clobous.com/%s/data/retrieve?%s",cloudid,name);
#if(INTERNET==1)

wifi_http(buff,responsex);

#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

		jsonparser(responsex,name,resultx);

       strcpy(valuex,resultx);
        
		

}






int rgb_retrieve(int *a,int *b,int *c)
{
char responsex[20];
char buff[80];
char resultx[10];

sprintf(buff,"http://api.clobous.com/%s/data/retrieve?r&g&b",cloudid);
#if(INTERNET==1)

wifi_http(buff,responsex);

#endif



#if(INTERNET==2)
 gprs_http((buff),responsex);
#endif

		jsonparser(responsex,"r",resultx);
	
	   *a=  atoi(resultx);
	   
	  
	   
	   jsonparser(responsex,"g",resultx);
	
	   *b=  atoi(resultx);
	   
	 
	   
	   jsonparser(responsex,"b",resultx);
	
	   *c =  atoi(resultx);   
	


        return 1;

}


#endif
