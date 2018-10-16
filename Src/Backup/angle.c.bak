



short MPU6050_Get_Angle(float x,float y,float z,u8 dir)
{
	float temp;
	float res=0;
	switch(dir)
	{
		case 0:	//???Z????
						temp=sqrt((x*x+y*y))/z;
						res=atan(temp);
						break;
		case 1://???X????
						temp=x/sqrt((y*y+z*z));
						res=atan(temp);
						break;
		case 2://???Y????
						temp=y/sqrt((x*x+z*z));
						res=atan(temp);
						break;
	}
	return res*1800/3.14;//????????
	
}