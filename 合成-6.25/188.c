/* 当前文件是D:\Read\ammp.c*/
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define ANSI 1
#define MAXTOKEN 10
#define TOKENLENGTH 80
#ifdef ANSI
#endif
/* 当前文件是D:\Read\ammp.h*/

#define float double
#define NEXCLUDE 32
#ifdef QUARTIC
#define CUBIC
#endif
#ifdef QUINTIC
#define CUBIC
#define QUARTIC
#endif
#define NCLOSE 200
#define critical_precision double
#ifdef ALLSINGLE
#define critical_precision float
#endif
#ifdef ALLDOUBLE
#define float double
#endif
typedef struct{
	float x,y,z;
	critical_precision fx,fy,fz;
	int serial;
	float q,a,b,mass;
	void *next;
	char active;
	char name[9];
	float chi,jaa;
	float vx,vy,vz,vw,dx,dy,dz;
	float gx,gy,gz;
	float VP,px,py,pz,dpx,dpy,dpz;
	float qxx,qxy,qxz,qyy,qyz,qzz;
#ifdef CUBIC
	float qxxx,qxxy,qxxz,qxyy,qxyz,qxzz;
	float qyyy,qyyz,qyzz,qzzz;
#endif
#ifdef QUARTIC
	float qxxxx,qxxxy,qxxxz,qxxyy,qxxyz,qxxzz;
	float qxyyy,qxyyz,qxyzz,qxzzz;
	float qyyyy,qyyyz,qyyzz,qyzzz,qzzzz;
#endif
#ifdef QUINTIC
	float qxxxxx,qxxxxy,qxxxxz,qxxxyy,qxxxyz,qxxxzz;
	float qxxyyy,qxxyyz,qxxyzz,qxxzzz;
	float qxyyyy,qxyyyz,qxyyzz,qxyzzz,qxzzzz;
	float qyyyyy,qyyyyz,qyyyzz,qyyzzz,qyzzzz,qzzzzz;
#endif
	void *close[NCLOSE];
	void *excluded[NEXCLUDE];
	char exkind[NEXCLUDE];
	int  dontuse;
	} ATOM;
/* 当前文件是D:\Read\numeric.h*/

#ifdef NUMERIC_DEFINED


#else
#ifdef DEFINE_NUMERIC
#define NUMERIC_DEFINED
float one = 1.;
float two = 2.;
float three = 3.;
float four = 4.;
float five = 5.;
float six = 6.;
float seven = 7.;
float eight = 8.;
float nine = 9.;
float twelve = 12.;
float half = 0.5 ;
float third = 1./3;
float eightth = .125;
float fourteenth = 1./14;
#else
#define one 1.
#define two 2.
#define three 3.
#define four 4.
#define five 5.
#define six 6.
#define seven 7.
#define eight 8.
#define nine 9.
#define twelve 12.
#define half  0.5
#define third 1./3
#define eightth 1./8
#define fourteenth 1./14
#endif
#endif
#define ROOTHALF 0.7071067811865475244008444
#define ROOT2    1.4142135623730950488016887
#define PI 3.1415926535897932384626433
#define TWOPI 6.2831853071795864769252866
#define ROOTPI 1.7724538509055160272981674
#define BOHR 0.5291771
#define INVBOHR 1.8897265
#define HARTREE 313.8625
void aaerror ( char *);
int  a_ftodx( float , float );
void a_inactive_f_zero();
void get_bond( ATOM *, ATOM *[], int , int * );
void mom_param( int serial, float chi, float jaa );
void rand3( float *, float *, float * );
int  set_f_variable ( char *, float );
int a_inc_d( float lambda );
#ifndef FILE
#endif
void dump_angles( FILE * );
void dump_atoms( FILE * );
void dump_bonds( FILE * );
void dump_excludes( FILE * );
void dump_force( FILE * );
void dump_hybrids( FILE * );
void dump_noels( FILE * );
void dump_pdb( FILE *, int );
void dump_restrains( FILE * );
void dump_tethers( FILE * );
void dump_tgroup( FILE * );
void dump_torsions( FILE * );
void dump_variable( FILE * );
void dump_velocity( FILE * );
/* 当前文件是D:\Read\ammp.c*/

#define ANSI 1
#define MAXTOKEN 10
#define TOKENLENGTH 80
#ifdef ANSI
#endif
int main()
{
void read_eval_do();
	set_f_variable( "mxdq",  .05);
	set_f_variable( "mxcut",  6.);
	set_i_variable( "nostep", 1);
	read_eval_do( stdin,stdout);
	return 0;
}
/* 当前文件是D:\Read\analyze.c*/

#define ANSI 1
#ifdef ANSI
#endif
void analyze( vfs,nfs,ilow,ihigh,op )
int  (*vfs[])();
int nfs;
FILE *op;
int ilow,ihigh;
{
int v_bond(),f_bond(),v_angle(),f_angle();
int v_mmbond(),f_mmbond(),v_mmangle(),f_mmangle();
int v_nonbon(),f_nonbon(),v_torsion(),f_torsion();
int atom(),bond(),angle(),torsion();
int v_hybrid(),f_hybrid();
int restrain(),v_restrain(),f_restrain();
int tether(),v_tether(),f_tether();
int u_v_nonbon(), u_f_nonbon();
int v_noel(),a_noel();
int v_ho_noel();
int a_bond(),a_mmbond(),a_angle(),a_mmangle();
int a_nonbon(),a_torsion(),a_hybrid(),a_restrain();
int a_tether();
float V,T,vt;
int ifs;
int i,j;
i = ilow;
j = ihigh;
if( ihigh < ilow ) j = ilow;
V = 0.;
for( ifs = 0; ifs < nfs; ifs++ )
{
	vt = 0.;
	if( vfs[ifs] == v_bond)
	{ a_bond(&vt,0.,i,j,op);fprintf( op," %f bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_mmbond)
	{a_mmbond(&vt,0.,i,j,op); fprintf( op," %f mm bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_mmangle)
	{a_mmangle(&vt,0.,i,j,op); fprintf( op," %f mm angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_angle)
	{a_angle(&vt,0.,i,j,op); fprintf( op," %f angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_noel)
	{a_noel(&vt,0.,i,j,op); fprintf( op," %f noel energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_noel)
	{a_noel(&vt,0.,i,j,op); fprintf( op," %f noel energy\n",vt); goto DONE;}
	if( vfs[ifs] == u_v_nonbon)
	{a_nonbon(&vt,0.,i,j,op); fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_nonbon)
	{a_nonbon(&vt,0.,i,j,op); fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_torsion)
	{a_torsion(&vt,0.,i,j,op); fprintf( op," %f torsion energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_hybrid)
	{a_hybrid(&vt,0.,i,j,op); fprintf( op," %f hybrid energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_tether)
	{a_tether(&vt,0.,i,j,op); fprintf( op," %f tether restraint energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_restrain)
	{a_restrain(&vt,0.,i,j,op); fprintf( op," %f restraint bond energy\n",vt); goto DONE;}
DONE:
	V += vt;
	vt = 0.;
}
	fprintf( op," %f total potential energy\n",V);
}
/* 当前文件是D:\Read\angle.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM *atom1,*atom2,*atom3;
	float target,k;
	void *next;
	}  ANGLE;
#define ALONG sizeof(ANGLE)
ANGLE *angle_first = NULL;
ANGLE *angle_last = NULL;
int angle( p1,p2,p3,fk,bl)
	int p1,p2,p3;
	float bl,fk ;
	{
	ANGLE *new;
	ATOM *ap1,*ap2,*ap3,*a_m_serial();
	char line[80];
	int i;
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	ap3 = a_m_serial( p3 );
	if( (ap1 == NULL) || (ap2 == NULL) || (ap3==NULL) )
	{
	sprintf( line,"undefined atom in angle %d %d %d \0",p1,p2,p3);
	aaerror( line );
	return 0;
	}
	if( ( new = malloc( ALONG ) ) == NULL)
	{
	return 0;
	}
	
	if( angle_first == NULL) angle_first = new;
	if( angle_last == NULL) angle_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
	new -> atom3 = ap3;
	new -> target = bl;
	new -> k = fk;
	new -> next = new;
if( ap1->dontuse < NEXCLUDE)
{
		for( i=0; i< ap1->dontuse; i++)
		{
		if( ap1->excluded[i] == ap3) goto excluded1;
		}
ap1->excluded[ap1->dontuse] = ap3; (ap1->dontuse)++;
}else{
aaerror(" too many bonds to an atom increase NEXCLUDE in ammp.h");
exit(0);
}
excluded1:
if( ap3->dontuse < NEXCLUDE)
{
		for( i=0; i< ap3->dontuse; i++)
		{
		if( ap3->excluded[i] == ap1) goto excluded3;
		}
ap3->excluded[ap3->dontuse] = ap1; (ap3->dontuse)++;
}else{
aaerror(" too many bonds to an atom increase NEXCLUDE in ammp.h");
exit(0);
}
excluded3:
	angle_last -> next = new;
	angle_last = new;
	return 1;
	}
int v_angle( V, lambda )
	float *V,lambda;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active || a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	*V += bp->k * (bp->target-dp)*(bp->target-dp);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_angle(lambda)
float lambda;
{
	ANGLE *bp;
	float r,k,ux1,uy1,uz1,ux2,uy2,uz2;
	ATOM *a1,*a2,*a3;
	float x1,y1,z1,x2,y2,z2;
	float r1,r2,dtheta,dp;
	float r11,r22,sdth;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active|| a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r1 = sqrt(x1*x1+y1*y1+z1*z1);
	r2 = sqrt(x2*x2+y2*y2+z2*z2);
	if( r1 < 1.e-5 || r2 < 1.e-5) goto SKIP;
	r = r1*r2;
	if( r > 1.e-8){
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dtheta = acos(dp);
	sdth = sin(dtheta); if( sdth < 1.e-3) sdth = 1.e-3;
	r11 = r1*sdth; r22 = r2*sdth;
	ux1 = x2/r2 - dp*x1/r1;
	uy1 = y2/r2 - dp*y1/r1;
	uz1 = z2/r2 - dp*z1/r1;
	ux2 = x1/r1 - dp*x2/r2;
	uy2 = y1/r1 - dp*y2/r2;
	uz2 = z1/r1 - dp*z2/r2;
	dtheta = -2.*k*(bp->target - dtheta);
	ux1 = ux1*dtheta/r11;
	uy1 = uy1*dtheta/r11;
	uz1 = uz1*dtheta/r11;
	ux2 = ux2*dtheta/r22;
	uy2 = uy2*dtheta/r22;
	uz2 = uz2*dtheta/r22;
	if( a1->active)
	{
	a1->fx += ux1;
	a1->fy += uy1;
	a1->fz += uz1;
	}
	if( a2->active)
	{
	a2->fx += -ux1 - ux2;
	a2->fy += -uy1 - uy2;
	a2->fz += -uz1 - uz2;
	}
	if( a3->active)
	{
	a3->fx += ux2;
	a3->fy += uy2;
	a3->fz += uz2;
	}
	}	
	}	
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_angle( a1,bonded,mbond,inbond)
ATOM *a1, *bonded[];
int mbond,*inbond ;
{
	ANGLE *mine;
	mine = angle_first;
	*inbond = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		bonded[(*inbond)++] = mine->atom3;
	}
	if( mine->atom3 == a1)
	{
		bonded[(*inbond)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *inbond == mbond ) return;
	}		
}
void dump_angles( FILE *where )
{
	ANGLE *b;
	ATOM *a1,*a2,*a3;
	float rtodeg;
	b = angle_first;
	if( b == NULL ) return;
	rtodeg = 180./acos(-1.);
	while( (b->next != b) )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3;
	fprintf( where,"angle %d %d %d %f %f ;\n",a1->serial,a2->serial,
		a3-> serial,b->k,b->target*rtodeg);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3;
	fprintf( where,"angle %d %d %d %f %f ;\n",a1->serial,a2->serial,
		a3-> serial,b->k,b->target*rtodeg);
}	
int v_mmangle( V, lambda )
	float *V,lambda;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active || a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	dp = dp - bp->target;
	*V += bp->k*dp*dp*(1.-.014*dp+5.6e-5*dp*dp
	-7.e-7*dp*dp*dp +9e-10*dp*dp*dp*dp);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_mmangle(lambda)
float lambda;
{
	ANGLE *bp;
	float r,k,ux1,uy1,uz1,ux2,uy2,uz2;
	ATOM *a1,*a2,*a3;
	float x1,y1,z1,x2,y2,z2;
	float r1,r2,dtheta,dp;
	float r11,r22,sdth;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active|| a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r1 = sqrt(x1*x1+y1*y1+z1*z1);
	r2 = sqrt(x2*x2+y2*y2+z2*z2);
	if( r1 < 1.e-5 || r2 < 1.e-5) goto SKIP;
	r = r1*r2;
	if( r > 1.e-8){
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dtheta = acos(dp);
	sdth = sin(dtheta); if( sdth < 1.e-3) sdth = 1.e-3;
	r11 = r1*sdth; r22 = r2*sdth;
	ux1 = x2/r2 - dp*x1/r1;
	uy1 = y2/r2 - dp*y1/r1;
	uz1 = z2/r2 - dp*z1/r1;
	ux2 = x1/r1 - dp*x2/r2;
	uy2 = y1/r1 - dp*y2/r2;
	uz2 = z1/r1 - dp*z2/r2;
	dp = dtheta - bp->target;
	dtheta = k*dp*(2.-.014*3*dp+4*(5.6e-5)*dp*dp
	-5*(7.e-7)*dp*dp*dp +6*(9.e-10)*dp*dp*dp*dp);
	ux1 = ux1*dtheta/r11;
	uy1 = uy1*dtheta/r11;
	uz1 = uz1*dtheta/r11;
	ux2 = ux2*dtheta/r22;
	uy2 = uy2*dtheta/r22;
	uz2 = uz2*dtheta/r22;
	if( a1->active){
	a1->fx += ux1;
	a1->fy += uy1;
	a1->fz += uz1;
	}
	if( a2->active){
	a2->fx += -ux1 - ux2;
	a2->fy += -uy1 - uy2;
	a2->fz += -uz1 - uz2;
	}
	if( a3->active){
	a3->fx += ux2;
	a3->fy += uy2;
	a3->fz += uz2;
	}
	}	
	}	
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int a_angle( V, lambda, ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( (a1->serial >= ilow && a1->serial <= ihigh)
	||  (a2->serial >= ilow && a2->serial <= ihigh)
	||  (a3->serial >= ilow && a3->serial <= ihigh) )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	z2  = bp->k * (bp->target-dp)*(bp->target-dp);
	*V += z2;
	fprintf(op,"Angle %s %d %s %d %s %d E %f value %f error %f\n",
		a1->name,a1->serial,a2->name,a2->serial,a3->name,a3->serial
		,z2,dp*180./3.14159265,
		(dp-bp->target)*180./3.14159265);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int a_mmangle( V, lambda ,ilow,ihigh,op)
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( (a1->serial >= ilow && a1->serial <= ihigh)
	||  (a2->serial >= ilow && a2->serial <= ihigh)
	||  (a3->serial >= ilow && a3->serial <= ihigh) )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	dp = dp - bp->target;
	z2 = bp->k*dp*dp*(1.-.014*dp+5.6e-5*dp*dp
	-7.e-7*dp*dp*dp +9e-10*dp*dp*dp*dp);
	*V += z2;
	dp = dp + bp->target;
	fprintf(op,"mmAngle %s %d %s %d %s %d E %f value %f error %f\n",
		a1->name,a1->serial,a2->name,a2->serial,a3->name,a3->serial
		,z2,dp*180./3.14159265,
		(dp-bp->target)*180./3.14159265);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int v_c_angle( V, lambda )
	float *V,lambda;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	float C0,C1,C2;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active || a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	r = dp;
	dp = acos(dp);
	C0 = cos( bp->target);
	C2 = 1./(4. - 4*C0*C0);
	C1 = -4.*C2*C0;
	C0 = C2*(2*C0*C0 + 1);
	*V += 2*bp->k *( C0 + C1*r + C2*cos(dp*2));
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_c_angle(lambda)
float lambda;
{
	ANGLE *bp;
	float r,k,ux1,uy1,uz1,ux2,uy2,uz2;
	ATOM *a1,*a2,*a3;
	float x1,y1,z1,x2,y2,z2;
	float r1,r2,dtheta,dp;
	float r11,r22,sdth;
	float C0,C1,C2;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active|| a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r1 = sqrt(x1*x1+y1*y1+z1*z1);
	r2 = sqrt(x2*x2+y2*y2+z2*z2);
	if( r1 < 1.e-5 || r2 < 1.e-5) goto SKIP;
	r = r1*r2;
	if( r > 1.e-8){
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dtheta = acos(dp);
	sdth = sin(dtheta); if( sdth < 1.e-3) sdth = 1.e-3;
	r11 = r1*sdth; r22 = r2*sdth;
	ux1 = x2/r2 - dp*x1/r1;
	uy1 = y2/r2 - dp*y1/r1;
	uz1 = z2/r2 - dp*z1/r1;
	ux2 = x1/r1 - dp*x2/r2;
	uy2 = y1/r1 - dp*y2/r2;
	uz2 = z1/r1 - dp*z2/r2;
	C0 = cos( bp->target);
	C2 = 1./(4. - 4*C0*C0);
	C1 = -4.*C2*C0;
	C0 = C2*(2*C0*C0 + 1);
	dtheta = -2.*bp->k*(C1*sdth + 2*C2*sin(dtheta*2) );
	ux1 = ux1*dtheta/r11;
	uy1 = uy1*dtheta/r11;
	uz1 = uz1*dtheta/r11;
	ux2 = ux2*dtheta/r22;
	uy2 = uy2*dtheta/r22;
	uz2 = uz2*dtheta/r22;
	if( a1->active){
	a1->fx += ux1;
	a1->fy += uy1;
	a1->fz += uz1;
	}
	if( a2->active){
	a2->fx += -ux1 - ux2;
	a2->fy += -uy1 - uy2;
	a2->fz += -uz1 - uz2;
	}
	if( a3->active){
	a3->fx += ux2;
	a3->fy += uy2;
	a3->fz += uz2;
	}
	}	
	}	
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int a_c_angle( V, lambda, ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	float C0,C1,C2;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( (a1->serial >= ilow && a1->serial <= ihigh)
	||  (a2->serial >= ilow && a2->serial <= ihigh)
	||  (a3->serial >= ilow && a3->serial <= ihigh) )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	r = dp;
	dp = acos(dp);
	C0 = cos( bp->target);
	C2 = 1./(4. - 4*C0*C0);
	C1 = -4.*C2*C0;
	C0 = C2*(2*C0*C0 + 1);
	*V += 2*bp->k *( C0 + C1*r + C2*cos(dp*2));
	fprintf(op,"c Angle %s %d %s %d %s %d E %f value %f error %f\n",
		a1->name,a1->serial,a2->name,a2->serial,a3->name,a3->serial
		,z2,dp*180./3.14159265,
		(dp-bp->target)*180./3.14159265);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
gsdg_angle( who )
ATOM *who;
{
ANGLE *bp;
ATOM *ap,*ap1;
float r,r1,theta;
float bond_length();
bp = angle_first;
while( 1)
{ if( bp == NULL ) return 0 ;
	if( bp->atom1 == who ){
	ap1 = bp->atom2;
	ap = bp->atom3;
	r = bond_length(who,ap1); r1 = bond_length(ap1,ap);
	theta = r*r + r1*r1 -2*cos( bp->target) *r*r1;
	ap->vx = theta;
	ap->vy = bp->k;
	}
	if( bp->atom3 == who ){
	ap1 = bp->atom2;
	ap = bp->atom1;
	r = bond_length(who,ap1); r1 = bond_length(ap1,ap);
	theta = r*r + r1*r1 -2*cos( bp->target) *r*r1;
	ap->vx = theta;
	ap->vy = bp->k;
	}
if( bp == bp->next) return 0;
bp = bp->next;
}
}
int v_ho_angle( V, lambda )
	float *V,lambda;
{
	ANGLE *bp;
	float r,x1,y1,z1,x2,y2,z2;
	float dp;
	ATOM *a1,*a2,*a3;
	float hol,get_f_variable(),target;
	hol = get_f_variable("lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active || a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r = (( x1*x1+y1*y1+z1*z1)*(x2*x2+y2*y2+z2*z2));
	if( r > 1.e-8){
	r = sqrt(r);
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	target = hol*dp + (1.-hol)*bp->target;
	*V += bp->k * (target-dp)*(target-dp);
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_ho_angle(lambda)
float lambda;
{
	ANGLE *bp;
	float r,k,ux1,uy1,uz1,ux2,uy2,uz2;
	ATOM *a1,*a2,*a3;
	float x1,y1,z1,x2,y2,z2;
	float r1,r2,dtheta,dp;
	float r11,r22,sdth;
	float hol,get_f_variable(),target;
	hol = get_f_variable("lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	bp = angle_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	if( a1->active|| a2->active || a3->active )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	dp = x1*x2+y1*y2+z1*z2;
	r1 = sqrt(x1*x1+y1*y1+z1*z1);
	r2 = sqrt(x2*x2+y2*y2+z2*z2);
	if( r1 < 1.e-5 || r2 < 1.e-5) goto SKIP;
	r = r1*r2;
	if( r > 1.e-8){
	dp = dp/r;  if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dtheta = acos(dp);
	target = hol*dtheta + (1.-hol)*bp->target;
	sdth = sin(dtheta); if( sdth < 1.e-3) sdth = 1.e-3;
	r11 = r1*sdth; r22 = r2*sdth;
	ux1 = x2/r2 - dp*x1/r1;
	uy1 = y2/r2 - dp*y1/r1;
	uz1 = z2/r2 - dp*z1/r1;
	ux2 = x1/r1 - dp*x2/r2;
	uy2 = y1/r1 - dp*y2/r2;
	uz2 = z1/r1 - dp*z2/r2;
	dtheta = -2.*k*(target - dtheta)*(1.-hol);
	ux1 = ux1*dtheta/r11;
	uy1 = uy1*dtheta/r11;
	uz1 = uz1*dtheta/r11;
	ux2 = ux2*dtheta/r22;
	uy2 = uy2*dtheta/r22;
	uz2 = uz2*dtheta/r22;
	if( a1->active)
	{
	a1->fx += ux1;
	a1->fy += uy1;
	a1->fz += uz1;
	}
	if( a2->active)
	{
	a2->fx += -ux1 - ux2;
	a2->fy += -uy1 - uy2;
	a2->fz += -uz1 - uz2;
	}
	if( a3->active)
	{
	a3->fx += ux2;
	a3->fy += uy2;
	a3->fz += uz2;
	}
	}	
	}	
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
/* 当前文件是D:\Read\animate.c*/

#define ANSI 1
#ifdef ANSI
#endif
int v_maxwell( T,dx,dy,dz)
float T,dx,dy,dz;
{
	float randg();
	
	ATOM *ap,*a_next(),*bonded[10];
	int iflag,inbond;
	float vmag;
	float R;
	R = 1.987 ;
	iflag = -1;
	while( (ap= a_next(iflag++)) != NULL)
	{
	iflag = 1;
	if( ap->mass > 0.)
	{
	vmag = sqrt( 3.*R*T/ap->mass*4.184*1000.)* randg();
	rand3( &ap->vx,&ap->vy,&ap->vz);
	if( ap->active ){
	ap->vx = ap->vx*vmag + dx;
	ap->vy = ap->vy*vmag + dy;
	ap->vz = ap->vz*vmag + dz;
	}else{
	ap->vx = 0.;
	ap->vy = 0.;
	ap->vz = 0.;
	}
	}
	}
	iflag = -1;
	while( (ap= a_next(iflag)) != NULL)
	{
	iflag = 1;
		if( ap->mass <= 0.)
		{
		get_bond(ap,bonded,10,&inbond);
			if( inbond >= 0)
			{
			ap->vx = bonded[0]->vx;
			ap->vy = bonded[0]->vy;
			ap->vz = bonded[0]->vz;
			}
		}
	}
	return 1;
}
int v_rescale( T )
float T;
{
	ATOM *ap,*a_next();
	int iflag,a_number();
	float vmag,KE,target;
	float R;
	R = 1.987 ;
	target = 0.;
	target += .5*(3.*R*T)*4.184*1000*a_number();
	KE = 0.;
	iflag = -1;
	while( (ap= a_next(iflag++)) != NULL)
	{
	iflag = 1;
	if( ap->mass > 0.)
	{
	vmag = ap->vx*ap->vx+ap->vy*ap->vy+ap->vz*ap->vz;
	KE += ap->mass*vmag;	
	}}
	KE = KE *.5;
	if( KE == 0.)
	{ aaerror(" Cannot rescale a zero velocity field -use v_maxwell");
		return 0;
		}
	vmag = sqrt(target/KE);
	iflag = -1;
	while( (ap= a_next(iflag++)) != NULL)
	{
	iflag = 1;
	ap->vx = ap->vx*vmag;
	ap->vy = ap->vy*vmag;
	ap->vz = ap->vz*vmag;
	}
	return 1;
}
int verlet(forces,nforces, nstep,dtime)
int (*forces[])(),nforces;
int nstep;
float dtime;
{
	ATOM *bp,*ap,*a_next(),*bonded[10];
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	for( istep = 0.; istep< nstep; istep++)
	{
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( 0.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx += ap->fx/ap->mass*dtime*4.184e6;
		ap->vy += ap->fy/ap->mass*dtime*4.184e6;
		ap->vz += ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	a_inc_v(dtime);
	}
	return 1;
}
int pac(forces,nforces, nstep,dtime)
int (*forces[])(),nforces;
int nstep;
float dtime;
{
	ATOM *ap,*bp,*a_next(),*bonded[10];
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	for( istep = 0.; istep< nstep; istep++)
	{
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx =  ap->dx +  ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->dy  + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->dz  + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		iflag = 1;
		ap->x += .5*(ap->vx + ap->dx)*dtime;
		ap->y += .5*(ap->vy + ap->dy)*dtime;
		ap->z += .5*(ap->vz + ap->dz)*dtime;
	}
		
	}
	return 1;
}
int tpac(forces,nforces, nstep,dtime_real,T)
int (*forces[])(),nforces;
int nstep;
float dtime_real,T;
{
	ATOM *ap,*bp,*a_next(),*bonded[10];
	float ke,Tke,R;
	float alpha;
	float dtime;
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	R = 1.987;
	for( istep = 0.; istep< nstep; istep++)
	{
	ke = 0.;
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	ke += ap->mass*(
	ap->vx*ap->vx + ap->vy*ap->vy + ap->vz*ap->vz);
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	}
	Tke = 3*(imax)*R*4.184*1000;
	Tke = ke/Tke;
	dtime = dtime_real;
	if( Tke > 1.e-6)
	{	
	ke = sqrt(T/Tke);
	dtime = dtime_real/ke;
	if( dtime > 0.000020 ){
		tpac(forces,nforces,1,dtime_real*0.5,T);
		tpac(forces,nforces,1,dtime_real*0.5,T);
		goto SKIP;
			}
	ap = a_next(-1);
	bp =  ap;
	for( i=0; i< imax;  i++, ap = bp)
	{
	bp = a_next(1);
	ap->dx *= ke;
	ap->dy *= ke;
	ap->dz *= ke;
	}
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx = ap->dx  + ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->dy  + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->dz  + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		iflag = 1;
		ap->x += .5*(ap->vx + ap->dx)*dtime;
		ap->y += .5*(ap->vy + ap->dy)*dtime;
		ap->z += .5*(ap->vz + ap->dz)*dtime;
	}
SKIP: ;
		
	}
	return 1;
}
int pacpac(forces,nforces, nstep,dtime)
int (*forces[])(),nforces;
int nstep;
float dtime;
{
	ATOM *ap,*a_next(),*bp,*bonded[10];
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces,icorrect;
	int i,imax,a_number();
	for( istep = 0.; istep< nstep; istep++)
	{
	iflag = -1;
	while( (ap=a_next(iflag)) != NULL)
	{
	iflag = 1;
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	iflag = -1;
	while( (ap=a_next(iflag)) != NULL)
	{
	iflag = 1;
	if( ap->mass > 0.)
	{
		ap->gx = ap->vx;	
		ap->gy = ap->vy;	
		ap->gz = ap->vz;	
		ap->vx += ap->fx/ap->mass*dtime*4.184e6;
		ap->vy += ap->fy/ap->mass*dtime*4.184e6;
		ap->vz += ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	iflag = -1;
	while( (ap=a_next(iflag)) != NULL)
	{
	iflag = 1;
	if( ap->mass <= 0.)
		{
		ap->gx = ap->vx;	
		ap->gy = ap->vy;	
		ap->gz = ap->vz;	
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
		bp = a_next(1);
		ap->dx = ap->vx + ap->gx;
		ap->dy = ap->vy + ap->gy;
		ap->dz = ap->vz + ap->gz;
	}
	for( icorrect = 0;icorrect < 2; icorrect ++)
	{
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/4.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx = ap->gx + ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->gy + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->gz + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		ap->dx = ap->vx + ap->gx;
		ap->dy = ap->vy + ap->gy;
		ap->dz = ap->vz + ap->gz;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		ap->x += .5*(ap->vx + ap->gx)*dtime;
		ap->y += .5*(ap->vy + ap->gy)*dtime;
		ap->z += .5*(ap->vz + ap->gz)*dtime;
	}
		
	}
	return 1;
}
int hpac(forces,poten,nforces,nstep,dtime_real,H)
int (*forces[])(),(*poten[])(),nforces;
int nstep;
float dtime_real,H;
{
	ATOM *ap,*bp,*a_next(),*bonded[10];
	float ke,Tke;
	float alpha;
	float dtime;
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	for( istep = 0.; istep< nstep; istep++)
	{
	ke = 0.;
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	ke += ap->mass*(
	ap->vx*ap->vx + ap->vy*ap->vy + ap->vz*ap->vz);
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	}
	ke = ke*.5/4.184/1000/1000;
	Tke = 0.;
	for(i=0; i< nforces; i++)
		(*poten[i])(&Tke,0.);
	dtime = dtime_real;
	if( Tke < H )
	{	
	ke = sqrt((H-Tke)/ke);
	dtime = dtime_real/ke;
	if( dtime > 0.000020 ){
		hpac(forces,poten,nforces,1,dtime_real*0.5,H);
		hpac(forces,poten,nforces,1,dtime_real*0.5,H);
		goto SKIP;
			}
	ap = a_next(-1);
	bp =  ap;
	for( i=0; i< imax;  i++, ap = bp)
	{
	bp = a_next(1);
	ap->dx *= ke;
	ap->dy *= ke;
	ap->dz *= ke;
	}
	} else {
	aaerror("Warning in Hpac, Potential energy higher than target\n");
	a_v_zero();
	a_d_zero();
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx = ap->dx  + ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->dy  + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->dz  + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		iflag = 1;
		ap->x += .5*(ap->vx + ap->dx)*dtime;
		ap->y += .5*(ap->vy + ap->dy)*dtime;
		ap->z += .5*(ap->vz + ap->dz)*dtime;
	}
SKIP: ;
		
	}
	return 1;
}
int ppac(forces,nforces, nstep,dtime_real,P)
int (*forces[])(),nforces;
int nstep;
float dtime_real,P;
{
	ATOM *ap,*bp,*a_next(),*bonded[10];
	float p,Tp,R;
	float dtime,cx,cy,cz;
	float alpha;
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	R = 1.987;
	imax = a_number();
	if( imax <= 0 )return 0;
	for( istep = 0.; istep< nstep; istep++)
	{
	cx = 0.; cy = 0.; cz = 0.;	
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	cx += ap->x;
	cy += ap->y;
	cz += ap->z;
	}
	cx /= imax;
	cy /= imax;
	cz /= imax;
	p = 0.;
	Tp = 0.;
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
		bp = a_next(1);
		p += ap->vx*ap->vx*ap->mass;
		p += ap->vy*ap->vy*ap->mass;
		p += ap->vz*ap->vz*ap->mass;
		Tp += (ap->x-cx)*(ap->x-cx);
		Tp += (ap->y-cy)*(ap->y-cy);
		Tp += (ap->z-cz)*(ap->z-cz);
	}
	Tp = sqrt(Tp/imax);
	Tp = 4*PI/3*Tp*Tp*Tp;
	p = p/imax/Tp*.5;
	printf("P %f p %f Tp %f\n",P,p,Tp);
	dtime = dtime_real;
	p = (1.+.1*pow( p/P, 1./3.))/1.1;
	
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
		bp = a_next(1);
		ap->x *= p;
		ap->y *= p;
		ap->z *= p;
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx = ap->dx  + ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->dy  + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->dz  + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		iflag = 1;
		ap->x += .5*(ap->vx + ap->dx)*dtime;
		ap->y += .5*(ap->vy + ap->dy)*dtime;
		ap->z += .5*(ap->vz + ap->dz)*dtime;
	}
		
	}
	return 1;
}
int ptpac(forces,nforces, nstep,dtime_real,P,T)
int (*forces[])(),nforces;
int nstep;
float dtime_real,P,T;
{
	ATOM *ap,*bp,*a_next(),*bonded[10];
	float p,Tp,R;
	float Tk;
	float dtime,cx,cy,cz;
	float alpha;
	int inbond,iflag;
	int a_f_zero(),a_inc_v();
	int istep,iforces;
	int i,imax,a_number();
	R = 1.987;
	imax = a_number();
	if( imax <= 0 )return 0;
	for( istep = 0.; istep< nstep; istep++)
	{
	cx = 0.; cy = 0.; cz = 0.;	
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	ap->dx = ap->vx;
	ap->dy = ap->vy;
	ap->dz = ap->vz;
	cx += ap->x;
	cy += ap->y;
	cz += ap->z;
	}
	cx /= imax;
	cy /= imax;
	cz /= imax;
	p = 0.;
	Tp = 0.;
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
		bp = a_next(1);
		p += ap->vx*ap->vx*ap->mass;
		p += ap->vy*ap->vy*ap->mass;
		p += ap->vz*ap->vz*ap->mass;
		Tp += (ap->x-cx)*(ap->x-cx);
		Tp += (ap->y-cy)*(ap->y-cy);
		Tp += (ap->z-cz)*(ap->z-cz);
	}
	Tp = sqrt(Tp/imax);
	Tp = 4*PI/3*Tp*Tp*Tp;
	Tk = 3*imax*R*4.184*1000;
	Tk = p/Tk;
	if( Tk < 1.e-5) Tk = 1.;
	p = p/imax/Tp*.5;
	printf("P %f p %f Tp %f\n",P,p,Tp);
	Tk = sqrt(T/Tk);
	dtime = dtime_real/Tk;
	if( dtime > 0.000020 ){
		ptpac(forces,nforces,1,dtime_real*0.5,P,T);
		ptpac(forces,nforces,1,dtime_real*0.5,P,T);
		goto SKIP;
			}
	p = (1.+.1*pow( p/P, 1./3.))/1.1;
	
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
		bp = a_next(1);
		ap->vx *= Tk;	
		ap->vy *= Tk;	
		ap->vz *= Tk;	
		ap->dx *= Tk;	
		ap->dy *= Tk;	
		ap->dz *= Tk;	
		ap->x *= p;
		ap->y *= p;
		ap->z *= p;
	}
	a_f_zero();
	for( iforces=0;iforces<nforces; iforces++)
		(*forces[iforces])( dtime/2.);
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass > 0.)
	{
		ap->vx = ap->dx  + ap->fx/ap->mass*dtime*4.184e6;
		ap->vy = ap->dy  + ap->fy/ap->mass*dtime*4.184e6;
		ap->vz = ap->dz  + ap->fz/ap->mass*dtime*4.184e6;
	}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
	if( ap->mass <= 0.)
		{
get_bond(ap,bonded,10,&inbond);
if( inbond >= 0)
{
ap->vx = bonded[0]->vx;
ap->vy = bonded[0]->vy;
ap->vz = bonded[0]->vz;
}
		}
	}
	imax = a_number();
	ap = a_next(-1);
	bp = ap;
	for( i=0; i< imax; i++,ap = bp)
	{
	bp = a_next(1);
		iflag = 1;
		ap->x += .5*(ap->vx + ap->dx)*dtime;
		ap->y += .5*(ap->vy + ap->dy)*dtime;
		ap->z += .5*(ap->vz + ap->dz)*dtime;
	}
		
SKIP: ;
	}
	return 1;
}
/* 当前文件是D:\Read\anonbon.c*/

#define ANSI 1
#ifdef ANSI
#endif
int a_nonbon( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	float r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	int inbond,inangle,i,ii;
	ATOM *a1,*a2;
	ATOM *a_next( );
	float dielectric,ve,va,vh;
	float vel,val,vhl;
	float vtint,vtout, vtt;
	ATOM *a_m_serial();
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	cutoff = get_f_variable("cutoff");
	if( cutoff < 1.) cutoff = 1.e10;
	lcutoff = -cutoff;
	vtint = 0.; vtout = 0.; vtt = 0.;
	for( ii=ilow; ii<=ihigh; ii++)
	{
	a1 = a_m_serial(ii);
	if( a1 == NULL ) goto NOTANATOM;
	ve = 0.; va = 0.; vh = 0.;
	vel = 0.; val = 0.; vhl = 0.;
	a2 = a_next(-1);
	while(   (a2->next != NULL))
	{
	for(i = 0; i< a1->dontuse; i++)
		if( a2 == a1->excluded[i]) goto SKIP;
	if( lambda == 0.)
	{
	xt = (a1->x - a2->x);
	if( (xt > cutoff) || (xt < lcutoff) ) goto SKIP;
	yt =  (a1->y - a2->y);
	if( (yt > cutoff) || (yt < lcutoff) ) goto SKIP;
	zt =  (a1->z - a2->z);
	if( (zt > cutoff) || (zt < lcutoff) ) goto SKIP;
	} else
	{
	xt = (a1->x - a2->x +lambda*(a1->dx - a2->dx));
	if( (xt > cutoff) || (xt < lcutoff) ) goto SKIP;
	yt = (a1->y - a2->y +lambda*(a1->dy - a2->dy));
	if( (yt > cutoff) || (yt < lcutoff) ) goto SKIP;
	zt = (a1->z - a2->z +lambda*(a1->dz - a2->dz));
	if( (zt > cutoff) || (zt < lcutoff) ) goto SKIP;
	}
	r = xt*xt+yt*yt+zt*zt;
	r0 = sqrt(r); r = r*r*r ;
	ve += dielectric*a1->q*a2->q/r0;
	va -= a1->a*a2->a/r;
	vh += a1->b*a2->b/r/r;
	if( a2->serial < ilow || a2->serial > ihigh)
	{
	vel += dielectric*a1->q*a2->q/r0;
	val -= a1->a*a2->a/r;
	vhl += a1->b*a2->b/r/r;
	}
SKIP:
	if( a2->next == a2) break;
	a2 = a2->next;
	}
	fprintf(op,"Vnonbon internal %s %d Eq %f E6 %f E12 %f\n",
	a1->name,ii,ve-vel,va-val,vh-vhl);
	fprintf(op,"Vnonbon external %s %d Eq %f E6 %f E12 %f\n",a1->name
		,ii,vel,val,vhl);
	fprintf(op,"Vnonbon total    %s %d Eq %f E6 %f E12 %f\n",a1->name
		,ii,ve,va,vh);
	*V += ve + va + vh;
	vtint += ve -vel+ va -val + vh -vhl;
	vtout += vel + val + vhl;
	vtt  += ve + va + vh;
NOTANATOM:
	i = i;
	}
	fprintf(op," Vnonbon total internal %f \n",vtint);
	fprintf(op," Vnonbon total external %f \n",vtout);
	fprintf(op," Vnonbon total          %f \n",vtt);
	return 1;
}
/* 当前文件是D:\Read\atoms.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define ALONG sizeof(ATOM)
ATOM *first = NULL;
ATOM *last = NULL;
static int atomNUMBER=0,atomUPDATE=0;
int atom(x,y,z,serial,q,a,b,mass,name )
	float x,y,z,q,a,b,mass;
	int serial;
	char *name;
	{
	int i;
	static int highest=-1,lowest=-1;
	ATOM *new, *a_m_serial();
	char *ctemp;
	new = NULL;
	if( highest >= serial && lowest <= serial) new = a_m_serial( serial);
	if( new == NULL)
	{
	if( ( new = malloc( ALONG ) ) == NULL)
	{
	return 0;
	}
	new ->dontuse = 0;
	new ->dontuse = 1;
	new ->excluded[0] = new;
	new -> active = 1;
	for( i=0; i< NEXCLUDE; i++)
	 new->exkind[i] = 0;
	new->next = NULL;
	}
	
	if( first == NULL){ first = new;
	highest = serial; lowest = serial; }
	if( last == NULL) last = new;
	new ->x = x;
	new ->y = y;
	new ->z = z;
	new ->fx = 0.;
	new ->fy = 0.;
	new ->fz = 0.;
	new ->dx = 0.;
	new ->dy = 0.;
	new ->dz = 0.;
	new ->vx = 0.;
	new ->vy = 0.;
	new ->vz = 0.;
	new ->jaa = -1;	new->chi = -1;
	new ->px = 10e10;
	new ->py = 10e10;
	new ->pz = 10e10;
	new ->q = q;
	new ->a = a;
	new ->b = b;
	new ->serial = serial;
	new ->mass = mass;
	for(i=0;i<8; i++)
	{
		new->name[i] = *name;
		new->name[i+1] = '\0';
		if( *name == '\0') break;
		name++;
	}
	if( new->next == NULL)
	{
	new -> next = new;
	last -> next = new;
	last = new;
	}
	atomUPDATE = 1;
	if( highest < serial ) highest = serial;
	if( lowest > serial ) lowest = serial;
	return 1;
	}
int a_number()
{
	ATOM *ap;
	if( atomUPDATE )
	{
	atomUPDATE = 0;
	atomNUMBER = 0;
	if( first == NULL ) return 0 ;
	ap = first;
	while(1)
	{
		if( ap->next == NULL) break;
		atomNUMBER++;
		if( ap->next == ap ) break;
		ap = ap->next;
	}
	}
	return atomNUMBER;
}
ATOM *a_m_serial( serial )
int serial;
{
static ATOM *ap = NULL;
	static ATOM *lastmatched = NULL;
	int i , n, a_number();
	if( atomUPDATE) n= a_number();
	else n = atomNUMBER;
	ap = first;
if( ap == NULL) return NULL;
	if( lastmatched == NULL ) lastmatched = first;
		
	if( serial == lastmatched->serial) return lastmatched;
	if( serial > lastmatched->serial) ap = lastmatched;
	for( i=0; i< n; i++ )
{
if( ap-> serial == serial) {lastmatched = ap;return ap;}
if( ap == ap->next)ap = first ;
else ap = ap->next;
}
return NULL;
}
ATOM *a_next( flag )
int flag;
{
static ATOM *ap = NULL;
if( ap == NULL) ap = first ;
if( ap == NULL) return NULL;
	if( flag <= 0){ ap = first; return ap;}
if( ap == ap->next) return NULL;
ap = ap->next;
return ap;
}
int a_f_zero()
{
	ATOM *ap;
	ap = first;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> fx = 0.; ap -> fy = 0.; ap -> fz = 0.;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_d_zero()
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> dx = 0.; ap -> dy = 0.; ap -> dz = 0.;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_g_zero()
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> gx = 0.; ap -> gy = 0.; ap -> gz = 0.;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_v_zero()
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> vx = 0.; ap -> vy = 0.; ap -> vz = 0.;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_inc_f( lambda )
float lambda;
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> x += ap->fx*lambda;
	 ap->y += ap->fy*lambda; ap->z += ap->fz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_inc_d( float lambda )
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> x += ap->dx*lambda;
	 ap->y += ap->dy*lambda; ap->z += ap->dz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_inc_v( lambda )
float lambda;
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> x += ap->vx*lambda;
	 ap->y += ap->vy*lambda; ap->z += ap->vz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_ftodx( float lambda, float lamold )
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap -> dx =ap->dx*lamold+ ap->fx*lambda;
	 ap->dy =ap->dy*lamold+ ap->fy*lambda;
	 ap->dz =ap->dz*lamold+ ap->fz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_ftogx( lambda ,lamold)
float lambda,lamold;
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap->gx = ap->gx*lamold +  ap->fx*lambda;
	 ap->gy = ap->gy*lamold +  ap->fy*lambda;
	 ap->gz = ap->gz*lamold +  ap->fz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
int a_ftovx( lambda ,lamold)
float lambda,lamold;
{
	ATOM *ap;
	ap = first;
	if( ap == NULL) return 0;
	while(1)
	{
	if( ap->next == NULL) return 0;
	 ap->vx = ap->vx*lamold +  ap->fx*lambda;
	 ap->vy = ap->vy*lamold +  ap->fy*lambda;
	 ap->vz = ap->vz*lamold +  ap->fz*lambda;
	 if( ap == ap->next) return 1;
	 ap = ap->next;
	}
}
float a_max_f()
{
	float l2norm ,l2max;
	ATOM *ap;
	ap = first;
	l2max = -1.;
	if( ap == NULL) return l2max;
	while(1)
	{
	if( ap->next == NULL) return l2max;
	l2norm = ap->fx*ap->fx;
	l2norm += ap->fy*ap->fy;
	l2norm += ap->fz*ap->fz;
	if( l2norm > l2max )
		l2max = l2norm;
	 if( ap == ap->next) return l2max;
	 ap = ap->next;
	}
}
float a_max_d()
{
	float l2norm ,l2max;
	ATOM *ap;
	ap = first;
	l2max = -1.;
	if( ap == NULL) return l2max;
	while(1)
	{
	if( ap->next == NULL) return l2max;
	l2norm = ap->dx*ap->dx;
	l2norm += ap->dy*ap->dy;
	l2norm += ap->dz*ap->dz;
	if( l2norm > l2max )
		l2max = l2norm;
	 if( ap == ap->next) return l2max;
	 ap = ap->next;
	}
}
float a_l2_f(  )
{
	ATOM *ap;
	float l2;
	ap = first;
	if( ap == NULL) return 0.;
	l2 = 0.;
	while(1)
	{
	if( ap->next == NULL) return -l2;
	l2 += ap->fx*ap->fx ;
	l2 += ap->fy*ap->fy ;
	l2 += ap->fz*ap->fz ;
	 if( ap == ap->next) return l2;
	 ap = ap->next;
	}
}
float a_l2_g(  )
{
	ATOM *ap;
	float l2;
	ap = first;
	if( ap == NULL) return 0.;
	l2 = 0.;
	while(1)
	{
	if( ap->next == NULL) return -l2;
	l2 += ap->gx*ap->gx ;
	l2 += ap->gy*ap->gy ;
	l2 += ap->gz*ap->gz ;
	 if( ap == ap->next) return l2;
	 ap = ap->next;
	}
}
float a_l2_v(  )
{
	ATOM *ap;
	float l2;
	ap = first;
	if( ap == NULL) return 0.;
	l2 = 0.;
	while(1)
	{
	if( ap->next == NULL) return -l2;
	l2 += ap->vx*ap->vx ;
	l2 += ap->vy*ap->vy ;
	l2 += ap->vz*ap->vz ;
	 if( ap == ap->next) return l2;
	 ap = ap->next;
	}
}
float a_l2_d(  )
{
	ATOM *ap;
	float l2;
	ap = first;
	if( ap == NULL) return 0.;
	l2 = 0.;
	while(1)
	{
	if( ap->next == NULL) return -l2;
	l2 += ap->dx*ap->dx ;
	l2 += ap->dy*ap->dy ;
	l2 += ap->dz*ap->dz ;
	 if( ap == ap->next) return l2;
	 ap = ap->next;
	}
}
void dump_atoms( FILE *where )
{
	ATOM *a,*ap;
	ATOM *bonded[20];
	int i ,j ;
	void dump_excludes();
	a = first;
	if( a == NULL) return;
	while( (a->next != a)  )
	{
	if( a->next == NULL) return;
	fprintf( where,"atom %f %f %f %d %s %f %f %f %f ;\n",
		a->x,a->y,a->z,a->serial,a->name,a->q,a->a,a->b,
		a->mass );
	if( a->chi > 0 && a->jaa > 0)
	fprintf( where,"mompar %d %f %f;\n",
		a->serial,a->chi,a->jaa);
	if( !a->active) fprintf(where," inactive %d ;\n", a->serial);
		a = a->next;
	}
	if( a->next == NULL) return;
	fprintf( where,"atom %f %f %f %d %s %f %f %f %f ;\n",
		a->x,a->y,a->z,a->serial,a->name,a->q,a->a,a->b,
		a->mass );
	if( a->chi > 0 && a->jaa > 0)
	fprintf( where,"mompar %d %f %f;\n",
		a->serial,a->chi,a->jaa);
	if( !a->active) fprintf(where," inactive %d ;\n", a->serial);
	dump_excludes(where);
}
void dump_excludes( FILE *where )
{
	ATOM *a,*ap,*a_next();
	int istailored;
	int get_i_variable();
	int numatm,a_number();
	int i,j;
	numatm = a_number();
	if( numatm <= 0 ) return;
	for( i=0; i< numatm; i++)
	{
	a = a_next(i);
		for( j=0; j< a->dontuse; j++)
		{
		if( a->exkind[j] > 0) {
		ap = a->excluded[j];
		if( ap->serial > a->serial)
		fprintf( where," tailor exclude %d %d ;\n",
		a->serial, ap->serial);
					}
		}
	}
}
void dump_velocity( FILE *where )
{
	ATOM *a;
	a = first;
	if( a == NULL) return;
	while( (a->next != a)  )
	{
	if( a->next == NULL) return;
	fprintf( where,"velocity %d %f %f %f ;\n",
		a->serial,a->vx,a->vy,a->vz );
		a = a->next;
	}
	if( a->next == NULL) return;
	fprintf( where,"velocity %d %f %f %f ;\n",
		a->serial,a->vx,a->vy,a->vz );
}
int a_readvelocity( serial,vx,vy,vz)
int serial;
float vx,vy,vz;
{
	ATOM *ap,*a_m_serial();
	ap = a_m_serial( serial);
	if( ap == NULL) return 0;
	ap ->vx = vx;
	ap ->vy = vy;
	ap ->vz = vz;
	return 1;
}
void dump_force( FILE *where )
{
	ATOM *a;
	a = first;
	if( a == NULL) return;
	while( (a->next != a)  )
	{
	if( a->next == NULL) return;
	fprintf( where,"force %d %f %f %f %f %f %f ;\n",
		a->serial,a->x,a->y,a->z,a->fx,a->fy,a->fz );
		a = a->next;
	}
	if( a->next == NULL) return;
	fprintf( where,"force %d %f %f %f %f %f %f ;\n",
		a->serial,a->x,a->y,a->z,a->fx,a->fy,a->fz );
}
void dump_pdb( FILE *where, int res_mod )
{
	ATOM *a;
	char *np,resid[5],atid[5];
	int i,ires,iatom;
	a = first;
	iatom = 0;
	if( a == NULL) return;
	if( res_mod == 0 )
	{
		aaerror( " need a non-zero residue modulus in dump_pdb\n");
		return ;
	}
	while( (a->next != a)  )
	{
	if( a->next == NULL) return;
		iatom++;
		ires = a->serial/res_mod  ;
		np = a->name;
		while( strcmp(np,"sna.rkq") == 0)
		{ a= a->next;
		if( a->next == NULL ) return; ires = a->serial/res_mod;
		np = a->name; }
		for( i=0; i<5;i++)
		{ if(*np != '.')
			{ if( islower(*np)) {resid[i] = toupper(*np);}
				else{ resid[i] = *np;}}
			else{ resid[i] = '\0'; break; }
			if( *np == '\0') break;
			np++;
			}
		if( *np == '.') np++;
		for( i=0; i<5;i++)
		{ if(*np != '.')
			{ if( islower(*np)){ atid[i] = toupper(*np);}
				else{ atid[i] = *np;}}
			else{ atid[i] = '\0'; break; }
			if( *np == '\0' ) break;
			np++;
			}
	if( atid[0] == 'H')
	fprintf(where,
	"ATOM  %5d %-4s%c%-3s  %4d    %8.3f%8.3f%8.3f%6.2f%6.2f\n",
	iatom,atid,' ',resid,ires,a->x,a->y,a->z,1.,10.);
		else
	fprintf(where,
	"ATOM  %5d  %-4s%-3s  %4d    %8.3f%8.3f%8.3f%6.2f%6.2f\n",
	iatom,atid,resid,ires,a->x,a->y,a->z,1.,10.);
		a = a->next;
	}
	if( a->next == NULL) return;
	iatom++;
	ires = a->serial/res_mod ;
	np = a->name;
	if( strcmp(np,"sna.rkq") != 0)
	{
	for( i=0; i<5;i++)
	{ if(*np != '.')
		{ if( islower(*np)){ resid[i] = toupper(*np);}
			else{ resid[i] = *np;}}
		else{ resid[i] = '\0'; break; }
		if( *np == '\0') break;
		np++;
		}
		if( *np == '.') np++;
	for( i=0; i<5;i++)
	{ if(*np != '.')
		{if( islower(*np)){ atid[i] = toupper(*np);}
			else{ atid[i] = *np;}}
		else{ atid[i] = '\0'; break; }
		if( *np == '\0' ) break;
		np++;
		}
	if( atid[0] == 'H')
	fprintf(where,
	"ATOM  %5d %-4s%c%-3s  %4d    %8.3f%8.3f%8.3f%6.2f%6.2f\n",
	iatom,atid,' ',resid,ires,a->x,a->y,a->z,1.,10.);
		else
	fprintf(where,
	"ATOM  %5d  %-4s%-3s  %4d    %8.3f%8.3f%8.3f%6.2f%6.2f\n",
	iatom,atid,resid,ires,a->x,a->y,a->z,1.,10.);
	}
	fprintf(where,"END   \n");
}
float a_pr_beta()
{
	float a,b;
	ATOM *ap;
	ap = first;
	a = 0.; b = 0.; 	
	if( ap == NULL) return a;
	while(1)
	{
	if( ap->next == NULL) return 0.;
	 a += ap->fx*ap->fx;
	 a += ap->fy*ap->fy;
	 a += ap->fz*ap->fz;
	 a -= ap->gx*ap->fx;
	 a -= ap->gy*ap->fy;
	 a -= ap->gz*ap->fz;
	 b += ap->gx*ap->gx;
	 b += ap->gy*ap->gy;
	 b += ap->gz*ap->gz;
	 if( ap == ap->next)
	 {
	if( b  <= 1.e-5) { a = 0.; b = 1.;}
	 return a/b;
	 }
	 ap = ap->next;
	}
}
inactivate_non_zero (i1,i2)
int i1,i2 ;
{
int upper, lower;
ATOM *ap,*a_m_serial(),*a_next();
int i ,numatm,a_number();
	if( i2 == 0 )
	{
	ap = a_m_serial( i1) ;
	if( ap != NULL)
	ap -> active = 0;
	return 0;
	}
	upper = i2; lower = i1;
	if( i2 < i1 ) { lower = i2; upper = i1;}
	numatm = a_number();
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	if( ap->serial >= lower && ap->serial <= upper)
	if( ap->x != 0. && ap->y != 0. && ap->z != 0.)
	   ap->active = 0;
	}
	return 0;
}
inactivate (i1,i2)
int i1,i2 ;
{
int upper, lower;
ATOM *ap,*a_m_serial(),*a_next();
int i ,numatm,a_number();
	if( i2 == 0 )
	{
	ap = a_m_serial( i1) ;
	if( ap != NULL)
	ap -> active = 0;
	return 0;
	}
	upper = i2; lower = i1;
	if( i2 < i1 ) { lower = i2; upper = i1;}
	numatm = a_number();
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	if( ap->serial >= lower && ap->serial <= upper)
	   ap->active = 0;
	}
	return 0;
}
activate (i1,i2)
int i1,i2 ;
{
int upper, lower;
ATOM *ap,*a_m_serial(),*a_next();
int i ,numatm,a_number();
	if( i2 == 0 )
	{
	ap = a_m_serial( i1) ;
	if( ap != NULL)
	ap -> active = 1;
	return 0;
	}
	upper = i2; lower = i1;
	if( i2 < i1 ) { lower = i2; upper = i1;}
	numatm = a_number();
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	if( ap->serial >= lower && ap->serial <= upper)
	   ap->active = 1;
	}
	return 0;
}
void a_inactive_f_zero()
{
	int i ,numatom,a_number();
	ATOM *ap,*a_next();
	numatom = a_number();
	for( i=0; i< numatom ; i++)
	{
	ap = a_next(i);
	if( ap->active == 0)
	{  ap->fx = 0.; ap->fy = 0.; ap->fz = 0.; }
	}
}
/* 当前文件是D:\Read\bonds.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM *atom1,*atom2;
	float length,k;
	float dlength,dk;
	int ndiff;
	void *next;
	}  BOND;
#define BLONG sizeof(BOND)
BOND *bond_first = NULL;
BOND *bond_last = NULL;
int bond( p1,p2,bl,fk)
	int p1,p2;
	float bl,fk ;
	{
	ATOM *ap1,*ap2,*a_m_serial();
	BOND *new;
	int i;
	char line[80];
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	if( (ap1 == NULL) || (ap2 == NULL) )
	{
	sprintf( line,"undefined atom in bond %d %d \0",p1,p2);
	aaerror( line );
	return 0;
	}
	if( ( new = malloc( BLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( bond_first == NULL) bond_first = new;
	if( bond_last == NULL) bond_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
	new -> length = bl;
	new -> k = fk;
	new -> next = new;
	if( ap1->dontuse < NEXCLUDE)
	{
		for( i=0; i< ap1->dontuse; i++)
		if( ap1->excluded[i] == ap2) goto excluded1;	
		ap1->excluded[ap1->dontuse] = ap2; (ap1->dontuse)++;
	}else{
	aaerror(" too many bonds to an atom increase NEXCLUDE in ammp.h");
	exit(0);
	}
excluded1:
	if( ap2->dontuse < NEXCLUDE)
	{
		for( i=0; i< ap2->dontuse; i++)
		if( ap2->excluded[i] == ap1) goto excluded2;	
		ap2->excluded[ap2->dontuse] = ap1; (ap2->dontuse)++;
	}else{
	aaerror(" too many bonds to an atom increase NEXCLUDE in ammp.h");
	exit(0);
	}
excluded2:
	bond_last -> next = new;
	bond_last = new;
	return 1;
	}
int v_bond( V, lambda )
	float *V,lambda;
{
	BOND *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r); *V += bp->k*( r - bp->length)*(r - bp->length);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_bond(lambda)
float lambda;
{
	BOND *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-15)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	ux = 2*k*(r-bp->length)*ux;
	uy = 2*k*(r-bp->length)*uy;
	uz = 2*k*(r-bp->length)*uz;
	if( a1->active ){
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	}
	if( a2->active ){
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_bond( ATOM *a1, ATOM *bonded[], int mbond, int *inbond  )
{
	BOND *mine;
	mine = bond_first;
	*inbond = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		bonded[(*inbond)++] = mine->atom2;
	}
	if( mine->atom2 == a1)
	{
		bonded[(*inbond)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *inbond == mbond ) return;
	}		
}
void dump_bonds( FILE *where )
{
	BOND *b;
	ATOM *a1,*a2;
	b = bond_first;
	if( b == NULL ) return;
	while( (b->next != b) )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"bond %d %d %f %f ;\n",a1->serial,a2->serial,
		b->length,b->k);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"bond %d %d %f %f ;\n",a1->serial,a2->serial,
		b->length,b->k);
}	
int v_mmbond( V, lambda )
	float *V,lambda;
{
	BOND *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	r = r - bp->length;
	*V += bp->k*r*r*(1.-2.55*r+7.*2.55/12*r*r);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_mmbond(lambda)
float lambda;
{
	BOND *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	r = r - bp->length;
	ux = k*r*(2.-3*2.55*r+4*7*2.55*r*r/12)*ux;
	uy = k*r*(2.-3*2.55*r+4*7*2.55*r*r/12)*uy;
	uz = k*r*(2.-3*2.55*r+4*7*2.55*r*r/12)*uz;
	if( a1->active ){
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	}
	if( a2->active ){
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int a_bond( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	BOND *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	if(( a1->serial >= ilow && a1->serial <=ihigh)
	 ||( a2->serial >= ilow && a2->serial <=ihigh))
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);  zt = bp->k*( r - bp->length)*(r - bp->length);
	*V += zt;
	fprintf(op,"Bond %s %d %s %d E %f value %f error %f\n"
		,a1->name,a1->serial,a2->name,a2->serial,zt,r,r-bp->length);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int a_mmbond( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	BOND *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if(( a1->serial >= ilow && a1->serial <=ihigh)
	 ||( a2->serial >= ilow && a2->serial <=ihigh))
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	r = r - bp->length;
	zt = bp->k*r*r*(1.-2.55*r+7.*2.55/12*r*r);
	*V += zt;
	fprintf(op,"mmBond %s %d %s %d E %f value %f error %f\n"
		,a1->name,a1->serial,a2->name,a2->serial,zt,r+bp->length,r);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
float bond_length( a1,a2)
ATOM *a1, *a2;
{
BOND *bp;
bp = bond_first;
while(1)
{
if( bp == NULL ) return -1.;
if( a1 == bp->atom1 && a2 == bp->atom2) return bp->length;
if( a2 == bp->atom1 && a1 == bp->atom2) return bp->length;
if( bp == bp->next) return -1.;
bp = bp->next;
}
}
gsdg_bond( who)
ATOM *who;
{
BOND *bp;
ATOM *ap;
bp = bond_first;
	while(1)
	{ if( bp == NULL ) return 1;
	if( bp->atom1 == who )
	{ ap = bp->atom2; ap->vx = bp->length*bp->length; ap->vy = bp->k;}
	if( bp->atom2 == who )
	{ ap = bp->atom1; ap->vx = bp->length*bp->length; ap->vy = bp->k;}
	if( bp == bp->next) return 1;
	bp = bp->next;
	}
	return 0;
}
BOND *get_bond_pointer( a1,a2)
ATOM *a1, *a2;
{
BOND *bp;
	bp = bond_first;
	while(1)
	{
	if( bp == NULL ) return NULL;
	if( a1 == bp->atom1 && a2 == bp->atom2) return bp;
	if( a1 == bp->atom2 && a2 == bp->atom1) return bp;
	if( bp == bp->next) return NULL;
	bp = bp->next;
	}
	return NULL;
}
int v_ho_bond( V, lambda )
	float *V,lambda;
{
	BOND *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	float hol, get_f_variable();
	float target;
	hol = get_f_variable( "lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	target = hol*r + (1.-hol)*bp->length;
	 *V += bp->k*( r - target)*(r - target);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_ho_bond(lambda)
float lambda;
{
	BOND *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	float hol, get_f_variable();
	float target;
	hol = get_f_variable( "lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	bp = bond_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active )
	{
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-15)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	target = hol*r + (1.-hol)*bp->length;
	ux = 2*k*(r-target)*(1.- hol)*ux;
	uy = 2*k*(r-target)*(1.- hol)*uy;
	uz = 2*k*(r-target)*(1.- hol)*uz;
	if( a1->active ){
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	}
	if( a2->active ){
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
/* 当前文件是D:\Read\box.c*/

#define ANSI 1
#ifdef ANSI
#endif
int v_box( V,lambda)
float *V,lambda;
{
return 0;
}
int f_box( lambda)
float lambda;
{
	float bbox,get_f_variable();
	float xc,yc,zc;
	float rx,ry,rz;
	float rad, vmod,vf,vdot;
	ATOM *ap,*a_next();
	int natom,a_number();
	int i;
	natom = a_number();
	if( natom < 1) return 0;
	bbox = get_f_variable("bbox");
	if( bbox < 1.) return 0;
	xc = 0.; yc = 0.; zc = 0.;
	for( i=0;  i< natom; i++)
	{
	ap =  a_next(i);
	xc += ap->x ;
	yc += ap->y ;
	zc += ap->z ;
	}
	xc  /= natom;
	yc  /= natom;
	zc  /= natom;
	bbox = bbox*bbox;
	for( i=0; i< natom; i++)
	{
	ap = a_next(i);
	rx = ap->x -xc ;
	ry = ap->y -yc ;
	rz = ap->z -zc ;
	rad = rx*rx + ry*ry + rz*rz;
	if( rad > bbox )
	{
	rad = 1./sqrt(rad);
	rx *= rad;
	ry *= rad;
	rz *= rad;
	vmod = ap->vx*ap->vx + ap->vy*ap->vy + ap->vz*ap->vz;
	vdot = ap->vx*rx + ap->vy*ry + ap->vz*rz;
	if( vdot > 0. ){
		ap->vx -= vdot*rx;
		ap->vx -= vdot*rx;
		ap->vy -= vdot*ry;
		ap->vy -= vdot*ry;
		ap->vz -= vdot*rz;
		ap->vz -= vdot*rz;
		vf = ap->vx*ap->vx + ap->vy*ap->vy + ap->vz*ap->vz;
		if( vf > 0.) vmod = sqrt(vmod/vf);
	
		ap->vx *= vmod;
		ap->vy *= vmod;
		ap->vz *= vmod;
		ap->dx = ap->vx;
		ap->dy = ap->vy;
		ap->dz = ap->vz;
		
	}
		
	}
	}
	
	return 0;
}
/* 当前文件是D:\Read\eval.c*/

#define ANSI 1
#define MAXTOKEN 20
#define TOKENLENGTH 80
#ifdef ANSI
#endif
#ifdef ESV
#define NOTIME
#endif
#ifndef NOTIME
#define TIME
#endif
#ifdef GRACELESS
/* 当前文件是D:\Read\graceless.h*/

#ifdef GRACELESS
unsigned long __noshrink = 0;
size_t __minshrink = 16384;
double __minshrinkfactor = 0.001;
size_t __mingrow = 49152;
double __mingrowfactor = 0.1;
unsigned long __madvisor = 1;
unsigned long __small_buff = 0;
int __fast_free_max = 13;
#endif
#endif
int loadloop (FILE *, FILE *, char *);
void read_eval_do( ip,op )
FILE *ip,*op;
{
char line[4096], *ap, *ap1;
int  itemp[MAXTOKEN];
float ftemp[MAXTOKEN];
int inbuff;
int inliteral ;
int eval();
	inliteral = (1 == 0);
	if( ip == NULL)
	{
		aaerror(" cannot use input file \n");
		return ;
	}
	if( op == NULL)
	{
		aaerror(" cannot use output file \n");
		return;
	}
	inbuff = 0;
	while((line[inbuff]=fgetc(ip))!= (char)EOF)
	{
	if( !inliteral && line[inbuff] == '"') inliteral = (1==1);
	if(  inliteral && line[inbuff] == '"') inliteral = (1==0);
	if( !inliteral ){
	if( line[inbuff] == ',') line[inbuff] = ' ';
	if( line[inbuff] == '\t') line[inbuff] = ' ';
	if( line[inbuff] == '\n') line[inbuff] = ' ';
	if( line[inbuff] == ';')
	{
	line[inbuff] = '\0';
	if(eval(ip,op,line )<0) return;
	inbuff = 0;
	} else if( line[inbuff] != '\n') inbuff++;
		}
	 }
}
int  (*potentials[10])(),(*forces[10])(),nused=(-1);
int eval( ip,op,line )
FILE *ip,*op;
char *line;
{
FILE *newfile,*fopen(),*tmpfile();
char  token[MAXTOKEN][TOKENLENGTH],*ap, *ap1;
	
char   errmes[80];
int  itemp[MAXTOKEN],itoken,tisvariable(),tisint();
float ftemp[MAXTOKEN];
static  int  echo=1;
static int inloop = 1;
int get_i_variable(),set_i_variable();
float get_f_variable();
int v_bond(),f_bond(),v_angle(),f_angle();
int v_mmbond(),f_mmbond(),v_mmangle(),f_mmangle();
int v_c_angle(), f_c_angle();
int v_periodic(),f_periodic();
int v_nonbon(),f_nonbon(),v_torsion(),f_torsion();
int v_box(),f_box();
int u_v_nonbon(),u_f_nonbon();
int v_ho_bond(),f_ho_bond();
int v_ho_angle(),f_ho_angle();
int atom(),bond(),angle(),torsion(),a_readvelocity();
int restrain(),v_restrain(),f_restrain();
int tether(),v_tether(),f_tether(),alltether();
int v_ho_tether(),f_ho_tether();
int hybrid(),v_hybrid(),f_hybrid();
int noel(),v_noel(),f_noel();
int v_ho_noel(),f_ho_noel();
int math();
#ifdef TIME
clock_t clock();
#endif
int significance();
void gsdg();
void analyze();
void AMMPmonitor();
void AMMPmonitor_mute();
void mom_add(),mom();
void tailor_qab();
void tailor_include();
void tailor_exclude();
int verlet(),v_maxwell(),v_rescale();
int pac(),pacpac(),tpac(),hpac(),ppac();
int ptpac();
if( nused == -1) {
potentials[0] = v_bond;
potentials[1] = v_angle;
potentials[2] = u_v_nonbon;
potentials[3] = v_torsion;
potentials[4] = v_hybrid;
forces[0] = f_bond;
forces[1] = f_angle;
forces[2] = u_f_nonbon;
forces[3] = f_torsion;
forces[4] = f_hybrid;
nused = 5;
}
	for( itoken=0; itoken<MAXTOKEN; itoken++)
	{
		token[itoken][0] = '\0';
		itemp[itoken] = 0; ftemp[itoken] = 0.;
	}
	if( echo ) fprintf(op,"%s;\n",line);
	ap = line;
	for( itoken=0; itoken< MAXTOKEN; itoken++)
	{	
	ap1 = &token[itoken][0];
	*ap1 = '\0';
	while(*ap == ' ') ap++;
	if( *ap == '"') {
		ap++;
		while( *ap != '"' && *ap != '\0')
		{
			*(ap1++) = *(ap++);
		}
		if( *ap == '"' ) ap++;
			}else {
	if( itoken== 0 && *ap == '#') return 1;
	while(*ap != ' ' && *ap != '\0')
	{
		if( itoken == 0 ||  ( strcmp(&token[0][0],"read") != 0 &&
				    strcmp(&token[0][0],"output") != 0)  )
		{
		if( isupper(*ap))
		{*ap1 = tolower(*ap); }else{ *ap1 = *ap;}
		ap1++; ap++;
		} else {
		*ap1 = *ap; ap1++; ap++;
		}
	}
			}
	*ap1 = '\0';
	ap1 = &token[itoken][0];
	if( tisvariable(ap1) )
	{
		ftemp[itoken] = get_f_variable( ap1);
		itemp[itoken] = get_i_variable( ap1);
		} else{
		if( tisint(ap1) == 1  )
		{
		itemp[itoken] = atoi(ap1);	
		ftemp[itoken] = itemp[itoken];
		}else{
		 ftemp[itoken] = atof(ap1);	
		itemp[itoken] = (int)ftemp[itoken];
		}
	}
	if(*ap == '\0') break;
	}
	if( token[0][0]  == '\0') return 1 ;
	
	if( strcmp( &token[0][0], "atom" ) == 0 )
	{
	if(atom( ftemp[1],ftemp[2],ftemp[3],itemp[4],ftemp[6],
		ftemp[7],ftemp[8],ftemp[9],&token[5][0]) )
	{ } else {
	aaerror(" cannot add to atom structure -data structure error");
			exit(0); }
	goto DONE;
	}
	if( strcmp( &token[0][0], "bond" ) == 0 )
	{
	if( bond(itemp[1],itemp[2],ftemp[3],ftemp[4]))
	{ }else
	{
	 aaerror(" cannot add to bond structure -data structure error");
		exit(0); }
	goto DONE;
	}
	if( strcmp( &token[0][0], "restrain" ) == 0 )
	{
	if( restrain(itemp[1],itemp[2],ftemp[3],ftemp[4]))
	{ }else
	{ aaerror(" cannot add to restrain structure -data structure error");
	exit(0);}
	goto DONE;
	}
	if( strcmp( &token[0][0], "angle" ) == 0 )
	{
	ftemp[2] = 3.141592653589793/180.;
	ftemp[5] = ftemp[5]*ftemp[2];
	if( angle( itemp[1],itemp[2],itemp[3],ftemp[4],ftemp[5]) )
	{ } else
	{ aaerror(" cannot add to angle structure -data structure error");
	exit(0);}
	goto DONE;
	}
	if( strcmp( &token[0][0], "noel" ) == 0 )
	{
	if( noel(itemp[1],itemp[2],ftemp[3],ftemp[4],ftemp[5],
			ftemp[6],ftemp[7]))
	{ }else
	{
	 aaerror(" cannot add to noel structure -data structure error");
		exit(0); }
	goto DONE;
	}
	if( strcmp( &token[0][0], "torsion" ) == 0 )
	{
	ftemp[2] = acos(-1.)/180.; ftemp[7] = ftemp[7]*ftemp[2];
	if( torsion(itemp[1],itemp[2],itemp[3],itemp[4],ftemp[5],itemp[6],
			ftemp[7]) )
	{ } else
	{ aaerror(" cannot add to torsion structure -data structure error");
	exit(0);}
	goto DONE;
	}
	if( strcmp( &token[0][0], "hybrid" ) == 0 )
	{
	if(hybrid(itemp[1],itemp[2],itemp[3],itemp[4],ftemp[5],ftemp[6]))
	{ } else
	{ aaerror(" cannot add to hybrid structure -data structure error");
	exit(0);}
	goto DONE;
	}
	if( strcmp( &token[0][0], "velocity" ) == 0 )
	{
	if( a_readvelocity(itemp[1],ftemp[2],ftemp[3],ftemp[4]) )
	{ } else
	{ aaerror(" cannot update velocity -is this atom defined? ");
	exit(0);}
	goto DONE;
	}
	if( strcmp( &token[0][0], "tether" ) == 0 )
	{
	if( strcmp( &token[1][0], "all") == 0 )
	{
		if( alltether( ftemp[2] ) )
		{} else
		{ aaerror(" cannot add to tether structure -data structure error");
		exit(0);}
	}else
	{
		if( tether( itemp[1],ftemp[2],ftemp[3],ftemp[4],ftemp[5]) )
		{ } else
		{ aaerror(" cannot add to tether structure -data structure error");
	exit(0);}
	}
	goto DONE;
	}
	if( strcmp( &token[0][0],"tgroup") == 0)
	{
	tgroup( itemp[1],itemp[2],itemp[3],itemp[4],itemp[5],ftemp[6],itemp[7]);
	goto DONE ;
	}
	if( strcmp( &token[0][0],"tsearch") == 0)
	{
	tsearch( itemp[1],itemp[2],itemp[3],itemp[4],itemp[5],itemp[6],itemp[7],itemp[8]);
	goto DONE ;
	}
	if( strcmp( &token[0][0],"tset") == 0 )
	{
	tset( op,echo,itemp[1],itemp[2],itemp[3],itemp[4],ftemp[5]*3.141592653589793/180.);
	goto DONE ;
	}
	if( strcmp( &token[0][0],"tmin") == 0 )
	{
	tmin( op,echo,itemp[1],itemp[2],itemp[3],itemp[4],itemp[5],potentials,nused);
	goto DONE ;
	}
	if( strcmp( &token[0][0],"tmap") == 0 )
	{
	tmap( op,echo,potentials,nused,
	itemp[1],itemp[2],itemp[3],itemp[4],
	itemp[5],itemp[6],itemp[7],itemp[8],itemp[9],itemp[10]
	);
	goto DONE ;
	}
	if( strcmp( &token[0][0], "mompar" )== 0)
	{
	mom_param( itemp[1],ftemp[2],ftemp[3] );
	goto DONE;
	}
	if( strcmp( &token[0][0], "momadd" )== 0)
	{
	mom_add( itemp[1],itemp[2] );
	goto DONE;
	}
	if( strcmp( &token[0][0], "mom" )== 0)
	{
	mom( op,ftemp[1],itemp[2] );
	goto DONE;
	}
	if( strcmp( &token[0][0], "monitor" )== 0)
	{
	AMMPmonitor( potentials,forces,nused,op );
	goto DONE;
	}
	if( strcmp( &token[0][0], "mon2" )== 0)
	{
	AMMPmonitor_mute( potentials,forces,nused,op );
	goto DONE;
	}
	if( strcmp( &token[0][0], "nzinactive" ) == 0)
	{
	inactivate_non_zero( itemp[1],itemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "inactive" ) == 0)
	{
	inactivate( itemp[1],itemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "active" ) == 0)
	{
	activate( itemp[1],itemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0],"signify") ==0 )
	{
	significance(op);
	goto DONE;
	}
	if( strcmp( &token[0][0], "analyze" )== 0)
	{
	analyze( potentials,nused,itemp[1],itemp[2],op );
	goto DONE;
	}
	if( strcmp(&token[0][0] , "tailor" ) == 0)
	{
		if( strcmp(&token[1][0], "qab") == 0 )
		{
		tailor_qab( itemp[2], ftemp[3],ftemp[4],ftemp[5]);
		goto DONE;
		}
		if( strcmp(&token[1][0], "include") == 0 )
		{
		tailor_include( itemp[2],itemp[3]);
		goto DONE;
		}
		if( strcmp(&token[1][0], "exclude") == 0 )
		{
		tailor_exclude( itemp[2],itemp[3]);
		goto DONE;
		}
	aaerror(" undefined tailor option "); aaerror(&token[1][0]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "read" ) == 0 )
	{
	newfile = fopen( &token[1][0],"r");
	if( newfile == NULL )
	{ aaerror(" cannot open file for read "); aaerror(&token[1][0]); }
	 else
	{ read_eval_do(newfile,op); fclose(newfile); }
	goto DONE;
	}
	if( strcmp( &token[0][0], "output" ) == 0 )
	{
	if( itemp[2] > 0)
	{
	sprintf( errmes,"%s.%d",&token[1][0],itemp[2]);
	newfile = fopen( errmes,"w");
	} else {
	newfile = fopen( &token[1][0],"w");
	}
	if( newfile == NULL )
	{ aaerror(" cannot open file for write "); aaerror(&token[1][0]); }
	else
	{ read_eval_do(ip,newfile); }
	goto DONE;
	}
	if( strcmp( &token[0][0], "dump" ) == 0 )
	{
	for( itoken=1; itoken<MAXTOKEN; itoken++)
	{if( token[itoken][0] == '\0') goto DONE;
	if( strcmp(&token[itoken][0],"atom") == 0) dump_atoms( op);
	if( strcmp(&token[itoken][0],"bond") == 0) dump_bonds( op);
	if( strcmp(&token[itoken][0],"noel") == 0) dump_noels( op);
	if( strcmp(&token[itoken][0],"angle") == 0) dump_angles( op);
	if( strcmp(&token[itoken][0],"torsion") == 0) dump_torsions( op);
	if( strcmp(&token[itoken][0],"hybrid") == 0) dump_hybrids( op);
	if( strcmp(&token[itoken][0],"restrain") == 0) dump_restrains( op);
	if( strcmp(&token[itoken][0],"pdb") == 0) dump_pdb( op,100);
	if( strcmp(&token[itoken][0],"variable") == 0) dump_variable(op);
	if( strcmp(&token[itoken][0],"velocity") == 0) dump_velocity(op);
	if( strcmp(&token[itoken][0],"force") == 0) dump_force(op);
	if( strcmp(&token[itoken][0],"tether") == 0) dump_tethers(op);
	if( strcmp(&token[itoken][0],"tgroup") == 0) dump_tgroup(op);
	}
	goto DONE;
	}
	if( strcmp( &token[0][0], "use" ) == 0 )
	{
	for( itoken=1; itoken<MAXTOKEN; itoken++)
	{
	if( token[itoken][0] == '\0') goto DONE;
	if( strcmp(&token[itoken][0],"none") == 0) nused = 0;
	if( strcmp(&token[itoken][0],"nonbon") == 0)
	{forces[nused] = u_f_nonbon; potentials[nused++] = u_v_nonbon;}
	if( strcmp(&token[itoken][0],"bond") == 0)
	{forces[nused] = f_bond; potentials[nused++] = v_bond;}
	if( strcmp(&token[itoken][0],"mmbond") == 0)
	{forces[nused] = f_mmbond; potentials[nused++] = v_mmbond;}
	if( strcmp(&token[itoken][0],"hobond") == 0)
	{forces[nused] = f_ho_bond; potentials[nused++] = v_ho_bond;}
	if( strcmp(&token[itoken][0],"tether") == 0)
	{forces[nused] = f_tether; potentials[nused++] = v_tether;}
	if( strcmp(&token[itoken][0],"hotether") == 0)
	{forces[nused] = f_ho_tether; potentials[nused++] = v_ho_tether;}
	if( strcmp(&token[itoken][0],"restrain") == 0)
	{forces[nused] = f_restrain; potentials[nused++] = v_restrain;}
	if( strcmp(&token[itoken][0],"angle") == 0)
	{forces[nused] = f_angle; potentials[nused++] = v_angle;}
	if( strcmp(&token[itoken][0],"hoangle") == 0)
	{forces[nused] = f_ho_angle; potentials[nused++] = v_ho_angle;}
	if( strcmp(&token[itoken][0],"mmangle") == 0)
	{forces[nused] = f_mmangle; potentials[nused++] = v_mmangle;}
	if( strcmp(&token[itoken][0],"cangle") == 0)
	{forces[nused] = f_c_angle; potentials[nused++] = v_c_angle;}
	if( strcmp(&token[itoken][0],"torsion") == 0)
	{forces[nused] = f_torsion; potentials[nused++] = v_torsion;}
	if( strcmp(&token[itoken][0],"hybrid") == 0)
	{forces[nused] = f_hybrid; potentials[nused++] = v_hybrid;}
	if( strcmp(&token[itoken][0],"honoel") == 0)
	{forces[nused] = f_ho_noel; potentials[nused++] = v_ho_noel;}
	if( strcmp(&token[itoken][0],"noel") == 0)
	{forces[nused] = f_noel; potentials[nused++] = v_noel;}
	if( strcmp(&token[itoken][0],"box") == 0)
	{forces[nused] = f_box; potentials[nused++] = v_box;}
	}
	goto DONE;
	}
	if( strcmp( &token[0][0], "close" ) == 0 )
	{
		if( op != stdout )
		{
		fclose(op);
		return -1;
		}   goto DONE;
	}
	if( strcmp( &token[0][0], "seti" ) == 0 )
	{
	if( token[1][0] == '\0')
		{aaerror("seti requires a variable name: seti <name> value");
		goto DONE;
		}
	set_i_variable( &token[1][0], itemp[2]);
	goto DONE;	
	}
	if( strcmp( &token[0][0], "setf" ) == 0 )
	{
	if( token[1][0] == '\0')
		{aaerror("setf requires a variable name: setf <name> value");
		goto DONE;
		}
	set_f_variable( &token[1][0], ftemp[2]);
	goto DONE;	
	}
	if( math( token,ftemp,itemp,ip,op,echo ) > 0 ) goto DONE;
	if( strcmp( &token[0][0], "v_maxwell") == 0)
	{
	v_maxwell( ftemp[1],ftemp[2],ftemp[3],ftemp[4]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "v_rescale") == 0)
	{
	v_rescale( ftemp[1]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "verlet") == 0)
	{
	verlet( forces,nused, itemp[1],ftemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "pac") == 0)
	{
	pac( forces,nused, itemp[1],ftemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "tpac") == 0)
	{
	tpac( forces,nused, itemp[1],ftemp[2],ftemp[3]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "ppac") == 0)
	{
	ppac( forces,nused, itemp[1],ftemp[2],ftemp[3]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "ptpac") == 0)
	{
	ptpac( forces,nused, itemp[1],ftemp[2],ftemp[3],ftemp[4]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "hpac") == 0)
	{
	hpac( forces,potentials,nused, itemp[1],ftemp[2],ftemp[3]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "pacpac") == 0)
	{
	pacpac( forces,nused, itemp[1],ftemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "steep" ) == 0 )
	{
	if( nused <= 0) goto DONE;
	steep( potentials,forces,nused,itemp[1],ftemp[2]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "gsdg" ) == 0)
	{
	if( nused <= 0) goto DONE;
	gsdg( potentials,nused,itemp[1],itemp[2],itemp[3]);
	goto DONE;
	}
	if( strcmp( &token[0][0], "cngdel" ) == 0 )
	{
	if( nused <= 0) goto DONE;
	cngdel( potentials,forces,nused,itemp[1],itemp[2],ftemp[3],echo);
	goto DONE;
	}
#ifdef TIME
	if( strcmp( &token[0][0],"time") == 0)
	{
	fprintf( op," %f CPU \n",((float)clock())/CLOCKS_PER_SEC);
	goto DONE;
	}
#endif
	if( strcmp( &token[0][0],"echo" ) == 0)
	{
	echo = 1;
	if( strcmp( &token[1][0],"off") == 0) echo = 0;
	goto DONE;
	}
	if( strcmp( &token[0][0],"exit") ==0 ) exit(0);
	if( strcmp( &token[0][0],"loopi")  == 0)
	{
	if( token[1][0] == '\0')
	{ aaerror(" must have a label to loop to "); goto DONE;}
	if( itemp[4] == 0) itemp[4] = 1;
	newfile = tmpfile();	
	if( newfile == NULL )
	{ aaerror(" cannot open temporary file in loopi"); goto DONE; }
	loadloop( ip,newfile, &token[1][0]);
	if( itemp[4] > 0)
	{
	for( itemp[0] = itemp[2];itemp[0]< itemp[3];itemp[0]+=itemp[4])
	{
	inloop = -1;
	if( tisvariable(&token[2][0]))
	set_i_variable( &token[2][0], itemp[0]);
	rewind( newfile );
	 read_eval_do(newfile,op);
	}
	} else{
	for( itemp[0] = itemp[2];itemp[0]< itemp[3];itemp[0]+=itemp[4])
	{
	inloop = -1;
	if( tisvariable(&token[2][0]))
	set_i_variable( &token[2][0], itemp[0]);
	rewind( newfile );
	 read_eval_do(newfile,op);
	}
	}
	inloop = 1;
	fclose( newfile);
	goto DONE;
	}
	if( strcmp( &token[0][0],"loopf")  == 0)
	{
	if( token[1][0] == '\0')
	{ aaerror(" must have a label to loop to "); goto DONE;}
	if( ftemp[4] == 0.) ftemp[4] = 1.;
	newfile = tmpfile();	
	if( newfile == NULL )
	{ aaerror(" cannot open temporary file in loopi"); goto DONE; }
	loadloop( ip,newfile, &token[1][0]);
	if( ftemp[4] > 0.)
	{
	for( ftemp[0] = ftemp[2];ftemp[0]< ftemp[3];ftemp[0]+=ftemp[4])
	{
	inloop = -1;
	if( tisvariable(&token[2][0]))
	set_f_variable( &token[2][0], ftemp[0]);
	rewind( newfile );
	 read_eval_do(newfile,op);
	}
	} else  {
	for( ftemp[0] = ftemp[2];ftemp[0]> ftemp[3];ftemp[0]+=ftemp[4])
	{
	inloop = -1;
	if( tisvariable(&token[2][0]))
	set_f_variable( &token[2][0], ftemp[0]);
	rewind( newfile );
	 read_eval_do(newfile,op);
	}
	}
	inloop = 1;
	goto DONE;
	}
	for( itemp[0]=0; itemp[0] < TOKENLENGTH; itemp[0]++)
	{
	if( token[0][itemp[0]] == '\0' || token[0][itemp[0]] == ' ')
	{
	 if( itemp[0] == 0) break;
	 if( token[0][itemp[0]-1] == ':') return inloop;
	}
	}
	sprintf(&errmes[0]," unrecognized token >%s<",&token[0][0]);
	aaerror( errmes );
DONE:
	return 1;
}
void aaerror( char *line )
{
	fprintf(stderr ,"%s \n",line);
	return ;
}
int tisvariable( p )
	char *p;
{
	if( (*p != '+')&&(*p != '-')&& !(isdigit( (int) *p)) &&(*p != '.') )
	 return 1;
	p++;
	while( (*p != '\0') && (isdigit( (int) *p) ) ) p++;
	if( *p == '\0') return 0;
	if( (*p != '.') && (*p != 'e') ) return 1;
	p++;
	if( !(isdigit( (int) *p)) ){
	if( *p == '\0' ) return 0;
	if( (*p != '.') && (*p != 'e') ) return 1;
	p++;
		}
	if( *p == '\0') return 0;
	if( (*p != '+')&&(*p != '-')&& !(isdigit( (int) *p)) &&(*p != '.') )
	 return 1;
	p++;
	if( *p == '\0') return 0;
	while( (*p != '\0') && ((isdigit( (int) *p))||(*p=='.')) ) p++;
	if( *p == '\0') return 0;
	return 1;
}
int tisint( p)
char *p ;
{
	char *pp;
	pp = p;
	while( *pp != '\0')
	{ if( *pp == '.') return 0; pp++;}
	if( (*p != '+')&&(*p != '-')&& !(isdigit( (int) *p)) ) return 0;
	p++;
	while (*p != '\0')
	{
		if( !(isdigit( (int) *p )) ) return 0;
		p++;
	}
	return 1;
}
int loadloop( FILE *ip, FILE *tp,  char *label)
{
	char line[256], *fgets() ;
	char *sp,*wp;
	
	while( fgets(  line,256,ip) != NULL )
	{
	fputs( line,tp );
	fputs("\n",tp);
	sp = line;
	while( *sp == ' ' && *sp != '\0') sp++;
	if( *sp != '\0' )
		{
		wp = sp;
		while(*wp != ';' && *wp != ' ' && *wp != '\0')
			{ if( isupper(*wp)){*wp = (char)tolower((int)*wp);}
			 wp++;}
	if( *wp == ' ' ) *wp = '\0';
	if( *wp == ';' ) *wp = '\0';
		if( strcmp(sp,label) == 0 ) return 1;
		}
	}
	aaerror(" must have a label for looping ");
	sprintf(line," where is >%s< label ?\n",label);
	aaerror( line );
	return 0;
}
/* 当前文件是D:\Read\gsdg.c*/

#define ANSI 1
#ifdef ANSI
#endif
void gsdg( vfs,nfs,niter,low_serial,high_serial )
int (*vfs[])(),nfs;
int niter;
int low_serial,high_serial;
{
ATOM *ap,*bp,*a_next();
int numatm , a_number();
int iter, i,j,k;
float svec[3],rvec[3];
float x,y,z;
float gsdg_line_search();
int v_bond(),v_angle(),u_v_nonbon(),v_noel();
int v_mmbond(),v_mmangle(),v_c_angle(),v_nonbon();
int v_hybrid();
numatm = a_number();
if( low_serial > high_serial)
{ i = low_serial; low_serial = high_serial; high_serial = i;}
if( high_serial <= 0 )
{ for( i=0; i< numatm; i++)
	{ ap = a_next(i);
	if( high_serial < ap->serial ) high_serial = ap->serial;
	}
}
for( iter = 0; iter< niter; iter++)
{
printf(" iter %d starting ",iter);
fflush(stdout);
ap = a_next(-1);
for( i=0; i< numatm; i++)
{
if( ap == NULL ) break;
if( ap->serial >= low_serial && ap->serial <= high_serial )
{
if( ap->active){
for( j=0;j< numatm; j++)
{ bp = a_next(j);
bp->vx = 16.;
bp->vy = 0.;
}
for( j=0; j< nfs; j++)
{
	if( vfs[j] == v_nonbon || vfs[j] == u_v_nonbon)
	{ for( k=0; k< numatm; k++)
		{bp = a_next(k);
		bp->vy = -10; }
		break;
	}
}
for( j=0; j< nfs; j++)
{
	if( vfs[j] == v_bond || vfs[j] == v_mmbond ) gsdg_bond(ap);
	if( vfs[j] == v_angle || vfs[j] == v_mmangle || vfs[j] == v_c_angle) gsdg_angle(ap);
	if( vfs[j] == v_noel) gsdg_noel(ap);
	if( vfs[j] == v_hybrid) gsdg_hybrid(ap);
}
rvec[0] = 0;
rvec[1] = 0;
rvec[2] = 0;
rand3( &svec[0],&svec[1],&svec[2]);
x = gsdg_line_search( svec, &y,ap);
rvec[0] += y*svec[0];
rvec[1] += y*svec[1];
rvec[2] += y*svec[2];
rand3( &svec[0],&svec[1],&svec[2]);
x = gsdg_line_search( svec, &y,ap);
rvec[0] += y*svec[0];
rvec[1] += y*svec[1];
rvec[2] += y*svec[2];
rand3( &svec[0],&svec[1],&svec[2]);
x = gsdg_line_search( svec, &y,ap);
rvec[0] += y*svec[0];
rvec[1] += y*svec[1];
rvec[2] += y*svec[2];
x = gsdg_line_search( rvec,&y,ap);
ap->x += y*rvec[0];
ap->y += y*rvec[1];
ap->z += y*rvec[2];
}
}
if( ap == ap->next ) break;
ap = ap->next;
}
printf(" done \n");
}
}
float gsdg_line_search( vect, step,who )
float vect[3],*step;
ATOM *who;
{
float val;
float vt,lam;
int i,j;
float dstep;
float gsdg_dgeom();
val = gsdg_dgeom(vect,0.,who);
lam = 0;
*step = 0;
dstep = -.5;
for( i=0; i< 3; i++)
{
dstep *= -.5;
for( j = 0; j< 200 ; j++)
{
	lam += dstep;
	vt =  gsdg_dgeom(vect,lam,who);
	if( vt < val ){ *step = lam; val = vt;} else {break;}
}
if( j == 200) dstep *= -2;
}
return val;
}
float gsdg_dgeom( vect,lam,who)
ATOM *who;
float vect[3],lam;
{
int numatm,a_number();
int i;
float x,y,z;
ATOM *ap,*a_next();
float dt;
float dsum;
numatm = a_number();
x = who->x + vect[0]*lam;
y = who->y + vect[1]*lam;
z = who->z + vect[2]*lam;
dsum = 0.;
for( i=0; i< numatm; i++)
{
ap = a_next(i);
if( ap != who )
{
dt = (x -ap->x)*(x-ap->x);
dt += (y -ap->y)*(y-ap->y);
dt += (z -ap->z)*(z-ap->z);
if( ap->vy > 0 )
{
dsum += ap->vy*(ap->vx -dt)*(ap->vx -dt);
} else {
if( ap->vx > dt)
dsum -= ap->vy*(ap->vx -dt)*(ap->vx -dt);
}
}
}
return dsum;
}
int v_trace(V ,lambda )
float *V,lambda;
{
	int numatm,i,a_number();
	ATOM *ap,*a_next();
	float xc,yc,zc;
	float xt,yt,zt;
	float l_trace,get_f_variable();
	numatm = a_number();
	if( numatm < 2 ) return 0 ;
	l_trace = get_f_variable("trace");
	if( l_trace == 0.) l_trace = 1./numatm;
	
	xc = 0.; yc = 0.; zc = 0.;
	for( i=0; i< numatm; i++)
	{
		ap = a_next(i);
		xc += ap->x + lambda*ap->dx;
		yc += ap->y + lambda*ap->dy;
		zc += ap->z + lambda*ap->dz;
	}
	xc /= numatm; yc /= numatm; zc /= numatm;
	for( i=0; i< numatm; i++)
	{
		ap = a_next(i);
		xt = ap->x + lambda*ap->dx - xc;
		yt = ap->y + lambda*ap->dy - yc;
		zt = ap->z + lambda*ap->dz - zc;
		*V -= l_trace*( xt*xt + yt*yt + zt*zt);
	}
	return 0;
}
int f_trace(lambda )
float lambda;
{
	int numatm,i,a_number();
	ATOM *ap,*a_next();
	float xc,yc,zc;
	float xt,yt,zt;
	float l_trace,get_f_variable();
	numatm = a_number();
	if( numatm < 2 ) return 0;
	l_trace = get_f_variable("trace");
	if( l_trace == 0.) l_trace = 1./numatm;
	
	xc = 0.; yc = 0.; zc = 0.;
	for( i=0; i< numatm; i++)
	{
		ap = a_next(i);
		xc += ap->x + lambda*ap->dx;
		yc += ap->y + lambda*ap->dy;
		zc += ap->z + lambda*ap->dz;
	}
	xc /= numatm; yc /= numatm; zc /= numatm;
	l_trace = 2*l_trace*(1.-1./numatm);
	for( i=0; i< numatm; i++)
	{
		ap = a_next(i);
		xt = ap->x + lambda*ap->dx - xc;
		yt = ap->y + lambda*ap->dy - yc;
		zt = ap->z + lambda*ap->dz - zc;
		ap->fx += l_trace*xt;
		ap->fy += l_trace*yt;
		ap->fz += l_trace*zt;
	}
	return 0;
}
/* 当前文件是D:\Read\hybrid.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM  *atom1, *atom2, *atom3, *atom4;
	float k,offset;
	void  *next;
	}  HYBRID;
#define HLONG sizeof(HYBRID)
HYBRID  *hybrid_first = NULL;
HYBRID  *hybrid_last = NULL;
int hybrid( p1,p2,p3,p4,fk,off)
	int p1,p2,p3,p4;
	float fk,off;
{
	HYBRID  *new;
	ATOM  *ap1, *ap2, *ap3, *ap4, *a_m_serial();
	char line[80];
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	ap3 = a_m_serial( p3 );
	ap4 = a_m_serial( p4 );
	if( (ap1 == NULL) || (ap2 == NULL) || (ap3==NULL) || (ap4==NULL) )
	{
	sprintf( line,"undefined atom in hybrid %d %d %d %d \0",p1,p2,p3,p4);
	aaerror( line );
	return 0;
	}
	if( ( new = malloc((unsigned int) HLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( hybrid_first == NULL) hybrid_first = new;
	if( hybrid_last == NULL) hybrid_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
	new -> atom3 = ap3;
	new -> atom4 = ap4;
	new -> offset = off;
	new -> k = fk;
	new -> next = new;
	hybrid_last -> next = new;
	hybrid_last = new;
	return 1;
}
int v_hybrid( V, lambda )
	float *V,lambda;
{
	HYBRID  *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1;
	float hite;
	ATOM  *a1, *a2, *a3, *a4;
	bp = hybrid_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active || a2->active || a3->active || a4->active){
x1 = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
y1 = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
z1 = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
x2 = (a3->x -a1->x +lambda*(a3->dx-a1->dx));
y2 = (a3->y -a1->y +lambda*(a3->dy-a1->dy));
z2 = (a3->z -a1->z +lambda*(a3->dz-a1->dz));
x3 = (a4->x -a1->x +lambda*(a4->dx-a1->dx));
y3 = (a4->y -a1->y +lambda*(a4->dy-a1->dy));
z3 = (a4->z -a1->z +lambda*(a4->dz-a1->dz));
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
r = sqrt(r);
	hite = cx1*x3 + cy1*y3 + cz1*z3; hite = hite/r;
	*V += (bp->k)*(hite - bp->offset)*(hite - bp->offset) ;
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_hybrid(lambda)
float lambda;
{
	HYBRID  *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1;
	float dx,dy,dz;
	float hite;
	float df;
	float r3,c;
	ATOM  *a1, *a2, *a3,  *a4, *at;
	int i;
	bp = hybrid_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active || a2->active || a3->active || a4->active){
	for( i=0; i< 3; i++)
	{
x1 = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
y1 = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
z1 = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
x2 = (a3->x -a1->x +lambda*(a3->dx-a1->dx));
y2 = (a3->y -a1->y +lambda*(a3->dy-a1->dy));
z2 = (a3->z -a1->z +lambda*(a3->dz-a1->dz));
x3 = (a4->x -a1->x +lambda*(a4->dx-a1->dx));
y3 = (a4->y -a1->y +lambda*(a4->dy-a1->dy));
z3 = (a4->z -a1->z +lambda*(a4->dz-a1->dz));
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
r = sqrt(r);r3 = r*r*r;
	hite = cx1*x3 + cy1*y3 + cz1*z3; hite = hite/r;
	df =  2*bp->k*(bp->offset - hite)/3;
	a4->fx += df/r*cx1;
	a4->fy += df/r*cy1;
	a4->fz += df/r*cz1;
	a1->fx -= df/r*cx1;
	a1->fy -= df/r*cy1;
	a1->fz -= df/r*cz1;
	dx =  -cx1*x3/r3*df;
	dy =  -cy1*y3/r3*df;
	dz =  -cz1*z3/r3*df;
	c = df*( (-y3*z2+z3*y2)/r) ;
	c += dx*( y2*(x1*y2-x2*y1) - z2*(x2*z1-x1*z2));
	a2->fx += c; a1->fx -= c;
	c = df*( (-z3*x2+x3*z2)/r) ;
	c += dy*( z2*(y1*z2-y2*z1) - x2*(x1*y2-x2*y1));
	a2->fy += c; a1->fy -= c;
	c = df*( (-x3*y2+y3*x2)/r) ;
	c += dz*( x2*(x2*z1-x1*z2) - y2*(y1*z2-y2*z1));
	a2->fz += c; a1->fz -= c;
	c = df*( (-z3*y1+y3*z1)/r) ;
	c -= dx*( y1*(x1*y2-x2*y1) - z1*(x2*z1-x1*z2));
	a3->fx += c; a1->fx -= c;
	c = df*( (-x3*z1+z3*x1)/r) ;
	c -= dy*( z1*(y1*z2-y2*z1) - x1*(x1*y2-x2*y1));
	a3->fy += c; a1->fy -= c;
	c = df*( (-y3*x1+x3*y1)/r) ;
	c -= dz*( x1*(x2*z1-x1*z2) - y1*(y1*z2-y2*z1));
	a3->fz += c; a1->fz -= c;
	at = a1; a1 = a2; a2 = a3; a3 = at;
	}
	if( a1->active == 0){ a1->fx = 0; a1->fy = 0.; a1->fz = 0;}
	if( a2->active == 0){ a2->fx = 0; a2->fy = 0.; a2->fz = 0;}
	if( a3->active == 0){ a3->fx = 0; a3->fy = 0.; a3->fz = 0;}
	if( a4->active == 0){ a4->fx = 0; a4->fy = 0.; a4->fz = 0;}
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_hybrid( a1,bonded,mbond,inbond)
ATOM  *a1,  *bonded[];
int mbond,*inbond ;
{
	HYBRID  *mine;
	mine = hybrid_first;
	*inbond = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		bonded[(*inbond)++] = mine->atom4;
	}
	if( mine->atom4 == a1)
	{
		bonded[(*inbond)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *inbond == mbond ) return;
	}		
}
void dump_hybrids( FILE *where )
{
	HYBRID  *b;
	ATOM  *a1, *a2, *a3, *a4;
	b = hybrid_first;
	if( b == NULL ) return;
	while( (b->next != b)  )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3; a4 = b->atom4;
	fprintf( where,"hybrid %d %d %d %d %f %f ;\n",
		a1->serial,a2->serial,
		a3-> serial,a4->serial,b->k,b->offset);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3; a4 = b->atom4;
	fprintf( where,"hybrid %d %d %d %d %f %f ;\n",
		a1->serial,a2->serial,
		a3-> serial,a4->serial,b->k,b->offset);
}	
int a_hybrid( V, lambda ,ilow,ihigh,op)
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	HYBRID  *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1;
	float hite;
	ATOM  *a1, *a2, *a3, *a4;
	bp = hybrid_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( (a1->serial >= ilow && a1->serial <= ihigh)
	||  (a2->serial >= ilow && a2->serial <= ihigh)
	||  (a3->serial >= ilow && a3->serial <= ihigh)
	||  (a4->serial >= ilow && a4->serial <= ihigh) )
	{
x1 = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
y1 = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
z1 = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
x2 = (a3->x -a1->x +lambda*(a3->dx-a1->dx));
y2 = (a3->y -a1->y +lambda*(a3->dy-a1->dy));
z2 = (a3->z -a1->z +lambda*(a3->dz-a1->dz));
x3 = (a4->x -a1->x +lambda*(a4->dx-a1->dx));
y3 = (a4->y -a1->y +lambda*(a4->dy-a1->dy));
z3 = (a4->z -a1->z +lambda*(a4->dz-a1->dz));
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
r = sqrt(r);
	hite = cx1*x3 + cy1*y3 + cz1*z3; hite = hite/r;
	z2 = (bp->k)*(hite - bp->offset)*(hite - bp->offset) ;
	*V += z2;
	fprintf(op,"Hybrid %s %d %s %d %s %d %s %d E %f value %f error %f\n",
	a1->name,a1->serial,a2->name,a2->serial,a3->name,a3->serial,a4->name,
	a4->serial,z2,hite,hite- bp->offset);
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int v_ho_hybrid( V, lambda )
	float *V,lambda;
{
	HYBRID  *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1;
	float hite;
	ATOM  *a1, *a2, *a3, *a4;
	float get_f_variable();
	float hol;
	hol = get_f_variable("lambda");
	if( hol >= 1.) return 0;
	if( hol <= 0.) hol = 0.;
	bp = hybrid_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active || a2->active || a3->active || a4->active){
x1 = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
y1 = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
z1 = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
x2 = (a3->x -a1->x +lambda*(a3->dx-a1->dx));
y2 = (a3->y -a1->y +lambda*(a3->dy-a1->dy));
z2 = (a3->z -a1->z +lambda*(a3->dz-a1->dz));
x3 = (a4->x -a1->x +lambda*(a4->dx-a1->dx));
y3 = (a4->y -a1->y +lambda*(a4->dy-a1->dy));
z3 = (a4->z -a1->z +lambda*(a4->dz-a1->dz));
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
r = sqrt(r);
	hite = cx1*x3 + cy1*y3 + cz1*z3; hite = hite/r;
	r =  hite*(one+hol) - bp->offset*(one-hol)  ;
	*V += (bp->k)*r*r ;
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_ho_hybrid(lambda)
float lambda;
{
	HYBRID  *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1;
	float dx,dy,dz;
	float hite;
	float df;
	float r3,c;
	ATOM  *a1, *a2, *a3,  *a4, *at;
	int i;
	float get_f_variable(),hol;
	hol = get_f_variable("lambda");
	if( hol >= 1.) return 0;
	if( hol <= 0.) hol = 0.;
	bp = hybrid_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active || a2->active || a3->active || a4->active){
	for( i=0; i< 3; i++)
	{
x1 = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
y1 = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
z1 = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
x2 = (a3->x -a1->x +lambda*(a3->dx-a1->dx));
y2 = (a3->y -a1->y +lambda*(a3->dy-a1->dy));
z2 = (a3->z -a1->z +lambda*(a3->dz-a1->dz));
x3 = (a4->x -a1->x +lambda*(a4->dx-a1->dx));
y3 = (a4->y -a1->y +lambda*(a4->dy-a1->dy));
z3 = (a4->z -a1->z +lambda*(a4->dz-a1->dz));
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
r = sqrt(r);r3 = r*r*r;
	hite = cx1*x3 + cy1*y3 + cz1*z3; hite = hite/r;
	df =  2*bp->k*(one-hol)*((one-hol)*bp->offset - (one+hol)*hite)/3;
	a4->fx += df/r*cx1;
	a4->fy += df/r*cy1;
	a4->fz += df/r*cz1;
	a1->fx -= df/r*cx1;
	a1->fy -= df/r*cy1;
	a1->fz -= df/r*cz1;
	dx =  -cx1*x3/r3*df;
	dy =  -cy1*y3/r3*df;
	dz =  -cz1*z3/r3*df;
	c = df*( (-y3*z2+z3*y2)/r) ;
	c += dx*( y2*(x1*y2-x2*y1) - z2*(x2*z1-x1*z2));
	a2->fx += c; a1->fx -= c;
	c = df*( (-z3*x2+x3*z2)/r) ;
	c += dy*( z2*(y1*z2-y2*z1) - x2*(x1*y2-x2*y1));
	a2->fy += c; a1->fy -= c;
	c = df*( (-x3*y2+y3*x2)/r) ;
	c += dz*( x2*(x2*z1-x1*z2) - y2*(y1*z2-y2*z1));
	a2->fz += c; a1->fz -= c;
	c = df*( (-z3*y1+y3*z1)/r) ;
	c -= dx*( y1*(x1*y2-x2*y1) - z1*(x2*z1-x1*z2));
	a3->fx += c; a1->fx -= c;
	c = df*( (-x3*z1+z3*x1)/r) ;
	c -= dy*( z1*(y1*z2-y2*z1) - x1*(x1*y2-x2*y1));
	a3->fy += c; a1->fy -= c;
	c = df*( (-y3*x1+x3*y1)/r) ;
	c -= dz*( x1*(x2*z1-x1*z2) - y1*(y1*z2-y2*z1));
	a3->fz += c; a1->fz -= c;
	at = a1; a1 = a2; a2 = a3; a3 = at;
	}
	if( a1->active == 0){ a1->fx = 0; a1->fy = 0.; a1->fz = 0;}
	if( a2->active == 0){ a2->fx = 0; a2->fy = 0.; a2->fz = 0;}
	if( a3->active == 0){ a3->fx = 0; a3->fy = 0.; a3->fz = 0;}
	if( a4->active == 0){ a4->fx = 0; a4->fy = 0.; a4->fz = 0;}
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int gsdg_hybrid( who)
ATOM *who;
{
	ATOM *a1,*a2,*a3,*a4;
	int i;
	float x3,y3,z3;
	float x1,y1,z1;
	float x2,y2,z2;
	float hite,r,cx1,cy1,cz1;
	HYBRID *hp;
	if( hybrid_first == NULL ) return 0;
	hp = hybrid_first;
	if( !who->active ) return 0;
	while( hp != NULL)
	{
		
	a1 = hp->atom1; a2 = hp->atom2; a3 = hp->atom3;
	a4 = hp->atom4;
	if( a4 == who){
x1 = (a2->x -a1->x );
y1 = (a2->y -a1->y );
z1 = (a2->z -a1->z );
x2 = (a3->x -a1->x );
y2 = (a3->y -a1->y );
z2 = (a3->z -a1->z );
x3 = (a4->x -a1->x );
y3 = (a4->y -a1->y );
z3 = (a4->z -a1->z );
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < 1.e-16) goto SKIP;
	r = sqrt(r);r = 1./r;
	cx1 *= r;
	cy1 *= r;
	cz1 *= r;
	hite = cx1*x3 + cy1*y3 + cz1*z3;
	hite = hp->offset - hite;
	cx1 *= hite;
	cy1 *= hite;
	cz1 *= hite;
	a4->x += cx1;
	a4->y += cy1;
	a4->z += cz1;
SKIP: ;
	}
	if(hp->next == hp) break;
		hp = hp->next;
	}
return 1;
}
/* 当前文件是D:\Read\math.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define NUM_SIG 6
#define NUM_TOT 7
#define INTEGER 0
#define FLOAT 1
typedef struct{
	int type;
	char name[NUM_TOT];
	union{  float f; int i;} value;
	void *next;
	}  VARIABLE;
#define TOKENLENGTH 80
#define ATOMDATA 0
#define IMEADIATE 1
#define VARDATA 2
int math_findlabel (FILE *, char *);
int math_match_atom(char *who, ATOM *ap);

int math( tokens,fvalue,ivalue,ip,op,echo)
#ifdef ESV
#define tokens (*tokens)
#endif
char tokens[][TOKENLENGTH];
float fvalue[];
int ivalue[];
FILE *ip,*op;
int echo ;
{
int adata,bdata;
int atype, btype;
float *foutpointer,*fp,fa,fb,randf();
int *ioutpointer,ia,ib;
VARIABLE *vp,*vos,*match_variable();
float *getatomdata();
int validatom();
int set_i_variable();
int a_number(),tisint();
ATOM *ap,*a_next(),*a_m_serial();
int i,j;
float a_l2_f(),a_max_f(),a_max_d();
float linmin();
set_i_variable( "numatm",a_number());
set_f_variable( "l2f",a_l2_f());
set_f_variable( "lmaxf",a_max_f());
NEW_AVAR:
	if( (vp = match_variable(&tokens[1][0])) != NULL)
	{
	adata = VARDATA;
	atype = vp->type;
	vos = vp;
	if( atype == FLOAT){ fa = vp->value.f;}
	foutpointer  = &vp->value.f;
	if( atype == INTEGER){ia = vp->value.i; }
	ioutpointer = &vp->value.i;
	goto AFOUND;
	}
	if( (foutpointer = getatomdata(&tokens[1][0])) != NULL)
	{
	adata = ATOMDATA;
	atype = FLOAT;
	fa = *foutpointer;
	goto AFOUND;
	}
	if( validatom(&tokens[1][0]) != 0 ) return( 1);
	foutpointer = NULL;
	adata = IMEADIATE;
	fa = fvalue[1];
	ia = ivalue[1];
	atype = FLOAT;
	if( tisint( &tokens[1][0]) == 1) atype = INTEGER;
AFOUND:
	if( (vp = match_variable(&tokens[2][0])) != NULL)
	{
	btype = vp->type;
	if( btype == FLOAT) fb = vp->value.f;
	if( btype == INTEGER) ib = vp->value.i;
	goto BFOUND;
	}
	if( (fp = getatomdata(&tokens[2][0])) != NULL)
	{
	btype = FLOAT;
	fb = *fp;
	goto BFOUND;
	}
	if( validatom(&tokens[2][0]) != 0 ) return( 1);
	fb = fvalue[2];
	ib = ivalue[2];
	btype = FLOAT;
	if( tisint( &tokens[2][0]) == 1) btype = INTEGER;
BFOUND:
	if( atype == FLOAT) ia = (int)fa;
	if( atype == INTEGER) fa = (float)ia;
	if( btype == FLOAT) ib = (int)fb;
	if( btype == INTEGER) fb = (float)ib;
	if( strcmp( &tokens[0][0], "add" ) == 0 )
	{
	if( atype == FLOAT) fa = fa + fb;
	if( atype == INTEGER) ia = ia + ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "sub" ) == 0 )
	{
	if( atype == FLOAT) fa = fa - fb;
	if( atype == INTEGER) ia = ia - ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "mul" ) == 0 )
	{
	if( atype == FLOAT) fa = fa * fb;
	if( atype == INTEGER) ia = ia * ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "div" ) == 0 )
	{
	if( atype == FLOAT) fa = fa / fb;
	if( atype == INTEGER) ia = ia / ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "fix" ) == 0 )
	{
	if( adata == ATOMDATA ) {
		ia = (int)fa;
		*foutpointer = (float)ia;
		if( echo  ) fprintf(op,"%d \n",ia);
		return(1);
			}
	if( atype == FLOAT) {atype = INTEGER; ia = (int)fa;}
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "sqrt" ) == 0 )
	{
	if( adata == ATOMDATA ) {
		if( fa > 0.)
		*foutpointer = sqrt(fa);
		else
		*foutpointer = -sqrt(-fa);
		if( echo  ) fprintf(op,"%f \n",*foutpointer);
		return(1);
			}
		atype = FLOAT;
		if( fa > 0) fa = sqrt(fa);
		else fa = -sqrt(-fa);
	goto GOOD_OP;
	}
	if( strcmp(&tokens[0][0],"linmin") == 0)
	{
	fa = 0.;
	fa = linmin( potentials,nused, sqrt(a_max_d()) );
	if( echo) fprintf(op,"%f step to minimum\n",fa);
	a_inc_d(fa);
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "nop" ) == 0 )
	{
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "mov" ) == 0 )
	{
	ia = ib;
	fa = fb;
	atype = btype;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "max" ) == 0 )
	{
	if( atype == FLOAT && fa < fb) fa = fb;
	if( atype == INTEGER && ia < ib) ia = ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "min" ) == 0 )
	{
	if( atype == FLOAT && fa > fb) fa = fb;
	if( atype == INTEGER && ia > ib) ia = ib;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "randf" ) == 0 )
	{
	atype = FLOAT;
	fa = randf( -1 );
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "serial" ) == 0 )
	{
	ia = 100*ib-1;
	j = ia + 100;
	i = -1;
	while( (ap = a_next(i)) != NULL )
	{
	i = 1;
	if( ap->serial > ia && ap->serial < j)
	if( math_match_atom(&tokens[3][0],ap) != 0 ){
	atype = INTEGER;
	ia = ap->serial;
	goto GOOD_OP;
	}
	}
	ia = -1;
	atype = INTEGER;
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "index" ) == 0 )
	{
	ap = a_next(-1);
	for( i=0; i< ib; i++)
	 ap = a_next(i);
	 ia = ap->serial;
	 atype = INTEGER;
	 goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "jes" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	ap = a_m_serial( ia ); if( ap == NULL) return 1;
	if( strcmp( &ap->name[0], &tokens[2][0]) == 0)
		{
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "jnes" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	ap = a_m_serial( ia );
	if( ap == NULL) {
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
		goto GOOD_OP;
		}
	if( strcmp( &ap->name[0], &tokens[2][0]) != 0)
		{
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "jne" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	if( (atype == INTEGER && ia != ib ) ||
	    (atype == FLOAT && fa != fb ) )
	    {
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "je" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	if( (atype == INTEGER && ia == ib ) ||
	    (atype == FLOAT && fa == fb ) )
	    {
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "jg" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	if( (atype == INTEGER && ia > ib ) ||
	    (atype == FLOAT && fa > fb ) )
	    {
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
	if( strcmp( &tokens[0][0], "jl" ) == 0 )
	{
	if( tokens[3][0] == '\0')
	{ aaerror("label: required for a jump \n"); goto GOOD_OP;}
	if( (atype == INTEGER && ia < ib ) ||
	    (atype == FLOAT && fa < fb ) )
	    {
	     rewind(ip);
	    math_findlabel( ip,&tokens[3][0]);
	    }
	goto GOOD_OP;
	}
return(-1);
GOOD_OP:
	if( tisvariable(&tokens[1][0] ) && tokens[1][0] != '\0' && adata == IMEADIATE )
		{set_i_variable(&tokens[1][0],0); adata = VARDATA;
		vos = match_variable(&tokens[1][0]);
		foutpointer = &vos->value.f;
		ioutpointer = &vos->value.i;}
	if( adata != IMEADIATE )
	{
	if( adata == VARDATA) vos->type = atype;	
	if( adata == ATOMDATA ){
			if( atype == INTEGER){atype = FLOAT;}
				}
	if( atype == FLOAT && foutpointer != NULL) *foutpointer = fa;
	if( atype == INTEGER && ioutpointer != NULL) *ioutpointer = ia;
	}
	if( echo && atype == INTEGER ) fprintf(op,"%d \n",ia);
	if( echo && atype == FLOAT ) fprintf(op,"%f \n",fa);
	return( 1);
#ifdef ESV
#undef tokens
#endif
}
int validatom( who )
char *who;
{
char *cp,*pp,*cp1,*cp2,*cp3;
int i;
	cp = who;
	i = 0;
	while ( *cp != '\0')
	{
	if( *cp == '.') {i++;  pp = cp;}
	cp++;
	}
	if( i != 1) return (0 );
	cp = pp ; cp++;
	cp1 = cp; cp1++;
	cp2 = cp1; cp2++;
	cp3 = cp2; cp3++;
	if( *cp1 == '\0')
	{
	if( *cp == 'x') return (1);
	if( *cp == 'y') return (2);
	if( *cp == 'z') return (3);
	if( *cp == 'q') return (13);
	if( *cp == 'a') return (14);
	if( *cp == 'b') return (15);
	if( *cp == 'm') return (16);
	return (0);
	}
	if( *cp2 == '\0')
	{
	if( *cp == 'f') {
	if( *cp1 == 'x') return (4);
	if( *cp1 == 'y') return (5);
	if( *cp1 == 'z') return (6);
			}
	if( *cp == 'd' ){
	if( *cp1 == 'x') return (7);
	if( *cp1 == 'y') return (8);
	if( *cp1 == 'z') return (9);
			}
	if( *cp == 'v' ){
	if( *cp1 == 'x') return (10);
	if( *cp1 == 'y') return (11);
	if( *cp1 == 'z') return (12);
			}
	if( *cp == 'n' ) {
		if( *cp1 =='a') return 19;
			}
	}
	if( *cp3 == '\0')
	{
	if( *cp == 'c' && *cp1 == 'h' && *cp2 == 'i') return 17;
	if( *cp == 'j' && *cp1 == 'a' && *cp2 == 'a') return 18;
	}
	return (0);	
}
float *getatomdata( who )
char *who ;
{
int validatom();
int i,j;
char aser[TOKENLENGTH],*cp;
ATOM *ap,*a_m_serial();
VARIABLE *vp,*match_variable();
static float fx,fy,fz;
	i = validatom( who );
	if( i == 0 ) return ( NULL );
	
	cp = who; j = 0;
	while( *cp != '.')
	{ aser[j++] = *cp; cp++; }
	aser[j] = '\0';
	if( (vp = match_variable(aser)) == NULL)
	{ j = atoi(aser); } else {
		if( vp ->type == INTEGER) j = vp->value.i;
		if( vp ->type == FLOAT) j = (int)vp->value.f;
				}
	ap = a_m_serial(j);
	if( ap == NULL) return( NULL );
	if( i == 1 ) return ( &ap->x );
	if( i == 2 ) return ( &ap->y );
	if( i == 3 ) return ( &ap->z );
	if( i == 4 ) { fx = ap->fx ; return( &fx);}
	if( i == 5 ) { fy = ap->fy ; return(&fy);}
	if( i == 6 ) { fz = ap->fz ; return(&fz);}
	if( i == 7 ) return ( &ap->dx );
	if( i == 8 ) return ( &ap->dy );
	if( i == 9 ) return ( &ap->dz );
	if( i == 10 ) return ( &ap->vx );
	if( i == 11 ) return ( &ap->vy );
	if( i == 12 ) return ( &ap->vz );
	if( i == 13 ) return ( &ap->q );
	if( i == 14 ) return ( &ap->a );
	if( i == 15 ) return ( &ap->b );
	if( i == 16 ) return ( &ap->mass );
	if( i == 17 ) return ( &ap->chi );
	if( i == 18 ) return ( &ap->jaa );
	return (NULL );
}
int math_match_atom( who,ap)
char *who;
ATOM *ap;
{
	char *cp;
	cp = & ap->name[0];
	while( *cp != '.' )
	{
	if( *cp == '\0') return 0;
	cp++;
	}
	cp++;
	if( strcmp( who,cp ) == 0 )
	{ return 1; }
	return 0;
}
int math_findlabel( FILE *fp, char *label)
{
char *cp,*lp;
char llabel[TOKENLENGTH];
char myline[TOKENLENGTH];
int  inmyline;
int i;
char ac;
cp = label;
lp  = &llabel[0];
	while( *cp != '\0')
	{
		*lp = *cp ; lp++; cp ++;
	}
	cp = lp; cp--;
	if( *cp != ':'){ *lp = ':'; lp++;}
	*lp = '\0';
	inmyline = 0;
	lp  = &llabel[0];
	while( (i= fgetc( fp )) != EOF )
	{
	ac = (char)i;
	if( !isspace((int) ac) )
	{
	if( ac == ';')
	{
	myline[inmyline] = '\0';
	if( strcmp( lp,&myline[0]) == 0 ) return 0;
	inmyline = 0;
	}else{
	if( inmyline > TOKENLENGTH) inmyline = 0;
	myline[inmyline++] = ac;
	}
	}
	}
	return 0;
}
/* 当前文件是D:\Read\mom.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define MAXMOM 100
ATOM *mom_list[MAXMOM];
int in_mom_list = 0;
void mom( op,tq,niter)
FILE *op;
float tq;
int niter;
{
float (*v)[], (*Z)[],(*Zk)[];
float r,dx,dy,dz;
float dv,tv;
int i,j,row;
float mom_jab();
	if( in_mom_list == 0 ) return;
	if( niter <= 0 ) niter = 20;
	v = malloc( in_mom_list * sizeof(float)) ;
	Z = malloc( in_mom_list*in_mom_list * sizeof(float)) ;
	Zk = malloc( in_mom_list*in_mom_list * sizeof(float)) ;
	if( v == NULL || Z == NULL|| Zk == NULL)
	{ aaerror(" cannot allocate memory in mom\n"); return;}
	row = in_mom_list;
	for( i=0; i< row; i++)
	for( j=i+1; j< row; j++)
	{
	dx = mom_list[j]->x - mom_list[i]->x;
	dy = mom_list[j]->y - mom_list[i]->y;
	dz = mom_list[j]->z - mom_list[i]->z;
	r = sqrt(dx*dx + dy*dy + dz*dz);
	(*Zk)[i + j*row] = mom_jab(r,mom_list[i]->jaa,mom_list[j]->jaa);
	(*Zk)[j + i*row] = (*Zk)[i + j*row];
	}
	for( i=0; i< row; i++)
	{ (*Zk)[i+i*row] = mom_list[i]->jaa/2 ; }
	dv = 0;
	for( j=0; j< niter; j++)
	{
	for( i=0;i< row*row ; i++)
	(*Z)[i] = (*Zk)[i] ;
	for( i=0; i< row; i++)
	{ (*v)[i]  =  -mom_list[i]->chi; }
	tv = 0.;
	for( i=0; i< row; i++)
	{ tv += (*v)[i]; }
	tv = tv/row +dv;
	for( i=0; i< row; i++)
	 (*v)[i] -= tv;
	mom_solve( Z,v,row,row);
	tv = 0.;
	for( i=0; i< row; i++)
	{
	tv += (*v)[i];
	}
	
	dv += 14.4*(tv - tq)/row*.25;
	fprintf( op,"MoM iter %d error %e\n",j,tv-tq);
	}
	for( i=0; i< row; i++)
	{
	mom_list[i]->q = (*v)[i];
	}
	free(Zk) ;free( Z); free(v); in_mom_list = 0;
}
void mom_add( s1,s2)
int s1,s2;
{
int i,j;
ATOM *ap,*a_m_serial(),*a_next();
int a_number(),numatm;
	numatm = a_number();
	if( numatm == 0 ) return ;
	if( s2 > 0 && s1 > s2)
	{  i = s1; s1 = s2; s2 = i; }
	if( s2 > s1)
	{
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	if(  ap->serial >=s1 && ap->serial <= s2 )
	{
	if( ap->chi > 0. && ap->jaa > 0.)
	{
	for( j=0; j< in_mom_list; j++)
	{ if( mom_list[j] == ap) goto THERE_NOW; }
	mom_list[in_mom_list++ ] = ap;
THERE_NOW:
	if( in_mom_list == MAXMOM) in_mom_list --;	
	}
	}
	}
	return;
	}
	if( (ap = a_m_serial(s1)) != NULL)
	{
	if( ap->chi > 0. && ap->jaa > 0.)
	{
	for( j=0; j< in_mom_list; j++)
	{if( ap == mom_list[j]) goto THERE_AGAIN;}
	mom_list[in_mom_list++ ] = ap;
THERE_AGAIN:
	if( in_mom_list == MAXMOM) in_mom_list --;	
	}
	}
}
void mom_param( int serial, float chi, float jaa )
{
ATOM *ap,*a_m_serial();
	if( (ap = a_m_serial(serial)) == NULL)
	{ aaerror(" MOM> cannot modify non-extant atom "); return;}
	ap->chi = chi;
	ap->jaa = jaa;
}
float mom_jab( r,j1,j2 )
float r;
float j1,j2;
{
float a,b,b2,b3;
	if( r < 30.) {
		
		
		a = sqrt(j1*j2)/2.;
		
		r = 1.1*r;
		b = exp( -r );
		b2 = 1. +  (15*r - 9*r*r - r*r*r)/48.;
		return a/r*(b*b2);
		}
	return 14.4/r/2;
}
	mom_solve( matrix,vector,irow,ilead )
	int irow,ilead;
	float (*matrix)[];
	float (*vector)[];
	{
	 float quotient;
	int i,j,k;
	int  mpi,mpj,mpk;
	mpi = 0;
	for ( i=0 ; i < irow - 1 ; i++ )
	{
	j = i ;
	mpj = mpi;
	while ( (*matrix) [mpi + i] == 0)
		{
		if( j == irow )
			{ return (-1); }
		j ++;
		mpj += ilead;
		(*vector)[i] +=  (*vector)[j];
		for (k = i; k <irow  ; k++)
			{(*matrix)[mpi + k] += (*matrix)[mpj +k]; }
		}
	mpj = mpi +ilead ;
	for ( j= i+1; j < irow ; j++ )
	{
	if( (*matrix)[mpj + i] != 0 )
		{
		 quotient = (*matrix)[mpj + i]/(*matrix)[mpi + i];
		 (*vector)[j] -= (*vector)[i]*quotient;
		for ( k=i ; k< irow ; k++ )
		{ (*matrix)[mpj + k] -= (*matrix)[mpi + k]*quotient; }
		}
	mpj += ilead;
	}
	mpi += ilead;
	}
	mpi = 0;
	for ( i = 0; i < irow - 1 ; i++ )
	{
		k = irow - i - 1;
		mpj= 0;
		mpk =  k*ilead;
	for ( j = 0; j < k ; j++)
	{ (*vector)[j] -=(*matrix)[mpj+k]/(*matrix)[mpk+k]*(*vector)[k];
		mpj +=ilead; }
	}
	mpi = 0;
	for ( i=0; i <irow ; i++ )
	{ (*vector)[i] /= (*matrix)[mpi + i];
	mpi += ilead;    }
	return (0);
	}
/* 当前文件是D:\Read\monitor.c*/

#define ANSI 1
#ifdef ANSI
#endif
void AMMPmonitor( vfs,ffs,nfs,op )
int  (*vfs[])(),(*ffs[])();
int nfs;
FILE *op;
{
int v_bond(),f_bond(),v_angle(),f_angle();
int v_mmbond(),f_mmbond(),v_mmangle(),f_mmangle();
int v_ho_bond(),f_ho_bond(),v_ho_angle(),f_ho_angle();
int f_c_angle(),v_c_angle();
int v_nonbon(),f_nonbon(),v_torsion(),f_torsion();
int atom(),bond(),angle(),torsion();
int v_hybrid(),f_hybrid();
int restrain(),v_restrain(),f_restrain();
int tether(),v_tether(),f_tether();
int u_v_nonbon(), u_f_nonbon();
int v_noel(),f_noel();
int v_ho_noel(),f_ho_noel();
int a_number();
float mxdq,get_f_variable();
float V,T,vt;
float a_max_f(),a_l2_f();
ATOM *ap,*a_next();
int ifs,a_f_zero();
if( a_number() < 1)
{ aaerror(" no atoms defined - nothing to calculate \n"); return;}
V = 0.; T = 0.;
a_f_zero();
for( ifs = 0; ifs < nfs; ifs++ )
{
	vt = 0.;
	(*vfs[ifs])(&vt,0.);
	mxdq = get_f_variable("mxdq");
	set_f_variable("mxdq",100.);
	(*ffs[ifs])(0.);
	set_f_variable("mxdq",mxdq);
	V += vt;
	if( vfs[ifs] == v_bond)
	{ fprintf( op," %f bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_bond)
	{ fprintf( op," %f homotopy bond energy\n",vt);
		vt = 0; v_bond(&vt,0.);
	 fprintf( op," %f bond energy\n",vt);
		 goto DONE;}
	if( vfs[ifs] == v_mmbond)
	{ fprintf( op," %f mm bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_c_angle)
	{ fprintf( op," %f cangle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_mmangle)
	{ fprintf( op," %f mm angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_angle)
	{ fprintf( op," %f angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_angle)
	{ fprintf( op," %f homotopy angle energy\n",vt);
		vt = 0.; v_angle( &vt,0.);
	 	fprintf( op," %f angle energy\n",vt);
		goto DONE;}
	if( vfs[ifs] == v_noel)
	{ fprintf( op," %f noel energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_noel)
	{ fprintf( op," %f homotopy noel energy\n",vt);
		vt = 0.; v_noel( &vt,0.);
	 	fprintf( op," %f noel energy\n",vt);
	goto DONE;}
	if( vfs[ifs] == u_v_nonbon)
	{ fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_nonbon)
	{ fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_torsion)
	{ fprintf( op," %f torsion energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_hybrid)
	{ fprintf( op," %f hybrid energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_tether)
	{ fprintf( op," %f tether restraint energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_restrain)
	{ fprintf( op," %f restraint bond energy\n",vt); goto DONE;}
	fprintf( op," %f unknown potential type\n",vt);
DONE:
	vt = 0.;
}
	fprintf( op," %f total potential energy\n",V);
	set_f_variable( "l2f",a_l2_f());
	set_f_variable( "lmaxf",a_max_f());
	set_f_variable( "totalp",V);
	ifs = -1;
	while( (ap = a_next(ifs)) != NULL)
	{
		ifs = 1;
		T += ap->vx*ap->vx*ap->mass;
		T += ap->vy*ap->vy*ap->mass;
		T += ap->vz*ap->vz*ap->mass;
	}
	T = T*.5/4.184/1000/1000;
	set_f_variable("totalk",T);
	fprintf( op," %f total kinetic energy\n",T);
	fprintf( op," %f total energy\n",T+V);
	fprintf( op," %f total action\n",T-V);
}
void AMMPmonitor_mute( vfs,ffs,nfs,op )
int  (*vfs[])(),(*ffs[])();
int nfs;
FILE *op;
{
int v_bond(),f_bond(),v_angle(),f_angle();
int v_mmbond(),f_mmbond(),v_mmangle(),f_mmangle();
int v_ho_bond(),f_ho_bond(),v_ho_angle(),f_ho_angle();
int f_c_angle(),v_c_angle();
int v_nonbon(),f_nonbon(),v_torsion(),f_torsion();
int atom(),bond(),angle(),torsion();
int v_hybrid(),f_hybrid();
int restrain(),v_restrain(),f_restrain();
int tether(),v_tether(),f_tether();
int u_v_nonbon(), u_f_nonbon();
int v_noel(),f_noel();
int v_ho_noel(),f_ho_noel();
int a_number();
float mxdq,get_f_variable();
float V,T,vt;
float a_max_f(),a_l2_f();
ATOM *ap,*a_next();
int ifs,a_f_zero();
if( a_number() < 1)
{ aaerror(" no atoms defined - nothing to calculate \n"); return;}
V = 0.; T = 0.;
a_f_zero();
for( ifs = 0; ifs < nfs; ifs++ )
{
	vt = 0.;
	(*vfs[ifs])(&vt,0.);
	mxdq = get_f_variable("mxdq");
	set_f_variable("mxdq",100.);
	(*ffs[ifs])(0.);
	set_f_variable("mxdq",mxdq);
	V += vt;
#ifdef RWH_UNMUTED
	if( vfs[ifs] == v_bond)
	{ fprintf( op," %f bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_bond)
	{ fprintf( op," %f homotopy bond energy\n",vt);
		vt = 0; v_bond(&vt,0.);
	 fprintf( op," %f bond energy\n",vt);
		 goto DONE;}
	if( vfs[ifs] == v_mmbond)
	{ fprintf( op," %f mm bond energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_c_angle)
	{ fprintf( op," %f cangle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_mmangle)
	{ fprintf( op," %f mm angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_angle)
	{ fprintf( op," %f angle energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_angle)
	{ fprintf( op," %f homotopy angle energy\n",vt);
		vt = 0.; v_angle( &vt,0.);
	 	fprintf( op," %f angle energy\n",vt);
		goto DONE;}
	if( vfs[ifs] == v_noel)
	{ fprintf( op," %f noel energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_ho_noel)
	{ fprintf( op," %f homotopy noel energy\n",vt);
		vt = 0.; v_noel( &vt,0.);
	 	fprintf( op," %f noel energy\n",vt);
	goto DONE;}
	if( vfs[ifs] == u_v_nonbon)
	{ fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_nonbon)
	{ fprintf( op," %f non-bonded energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_torsion)
	{ fprintf( op," %f torsion energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_hybrid)
	{ fprintf( op," %f hybrid energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_tether)
	{ fprintf( op," %f tether restraint energy\n",vt); goto DONE;}
	if( vfs[ifs] == v_restrain)
	{ fprintf( op," %f restraint bond energy\n",vt); goto DONE;}
	fprintf( op," %f unknown potential type\n",vt);
DONE:
	vt = 0.;
#endif
}
	set_f_variable( "l2f",a_l2_f());
	set_f_variable( "lmaxf",a_max_f());
	set_f_variable( "totalp",V);
	ifs = -1;
	while( (ap = a_next(ifs)) != NULL)
	{
		ifs = 1;
		T += ap->vx*ap->vx*ap->mass;
		T += ap->vy*ap->vy*ap->mass;
		T += ap->vz*ap->vz*ap->mass;
	}
	T = T*.5/4.184/1000/1000;
	set_f_variable("totalk",T);
	fprintf( op," %f total energy\n",T+V);
}
/* 当前文件是D:\Read\noel.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM *atom1,*atom2;
	float d,dm,dh,km,kh;
	void *next;
	}  NOEL;
#define NOELLONG sizeof(NOEL)
NOEL *noel_first = NULL;
NOEL *noel_last = NULL;
int noel( p1,p2,d,dm,dh,km,kh)
	int p1,p2;
	float d,dm,dh,km,kh ;
	{
	ATOM *ap1,*ap2,*a_m_serial();
	NOEL *new;
	char line[80];
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	if( (ap1 == NULL) || (ap2 == NULL) )
	{
	sprintf( line,"undefined atom in noel %d %d \0",p1,p2);
	aaerror( line );
	return 0;
	}
	new = noel_first;
	if( new != NULL)
	{
	while(1)
	{
		if( new == NULL) break;
		if( (new->atom1 == ap1 && new->atom2 == ap2) ||
(new->atom1 == ap2 && new->atom2 == ap1) )
		{
		new->d = d; new->dm = dm; new->dh = dh;
		new->km = km; new->kh = kh; return 1;
		}
		if( new == new->next) break;
		new = new->next;
	}
	}
	if( ( new = malloc( NOELLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( noel_first == NULL) noel_first = new;
	if( noel_last == NULL) noel_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
		new->d = d; new->dm = dm; new->dh = dh;
		new->km = km; new->kh = kh;
	new -> next = new;
	noel_last -> next = new;
	noel_last = new;
	return 1;
	}
int v_noel( V, lambda )
	float *V,lambda;
{
	NOEL *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = noel_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active ){
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	if( r < bp->d -bp->dm)
	{
	r = r - bp->d + bp->dm;
	*V += bp->km * r*r;
	} else if( r > bp->d+ bp->dh) {
	r = r - bp->d - bp->dh;
	*V += bp->kh * r*r;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_noel(lambda)
float lambda;
{
	NOEL *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	bp = noel_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active){
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	if( r < bp->d -bp->dm)
	{
	r = r - bp->d + bp->dm;
	ux = 2*bp->km * r *ux;
	uy = 2*bp->km * r *uy;
	uz = 2*bp->km * r *uz;
	} else if( r > bp->d+ bp->dh) {
	r = r - bp->d - bp->dh;
	ux = 2*bp->kh * r *ux;
	uy = 2*bp->kh * r *uy;
	uz = 2*bp->kh * r *uz;
	}else{
	ux = 0.; uy = 0.; uz = 0.;
	}
	if( a1->active){
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	}
	if( a2->active) {
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_noel( a1,noeled,mnoel,innoel)
ATOM *a1, *noeled[];
int mnoel,*innoel ;
{
	NOEL *mine;
	mine = noel_first;
	*innoel = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		noeled[(*innoel)++] = mine->atom2;
	}
	if( mine->atom2 == a1)
	{
		noeled[(*innoel)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *innoel == mnoel ) return;
	}		
}
void dump_noels( FILE *where )
{
	NOEL *b;
	ATOM *a1,*a2;
	b = noel_first;
	if( b == NULL ) return;
	while( (b->next != b) )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"noel %d %d %f %f %f %f %f;\n",a1->serial,a2->serial,
		b->d, b->dm, b->dh, b->km, b->kh);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"noel %d %d %f %f %f %f %f ;\n",a1->serial,a2->serial,
		b->d, b->dm, b->dh, b->km, b->kh);
}	
int a_noel( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	NOEL *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = noel_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if(( a1->serial >= ilow && a1->serial <=ihigh)
	 ||( a2->serial >= ilow && a2->serial <=ihigh))
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	zt = 0;
	if( r < bp->d -bp->dm)
	zt= bp->km*( r - bp->d+ bp->dm)*(r - bp->d+ bp->dm);
	if( r > bp->d +bp->dh)
	zt= bp->kh*( r - bp->d- bp->dh)*(r - bp->d- bp->dh);
	*V += zt;
	fprintf(op,"NOEl %s %d %s %d E %f value %f error %f\n"
	,a1->name,a1->serial,a2->name,a2->serial,zt,r,r-bp->d);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int gsdg_noel( ap)
ATOM *ap;
{
	ATOM *bp;
	NOEL *np;
	np = noel_first;
	while(1)
	{ if( np == NULL ) return 1;
	if( np->atom1 == ap )
	{  bp = np->atom2; bp->vx = (np->d*np->d);
	   bp->vy = np->km; }
	if( np->atom2 == ap )
	{  bp = np->atom1; bp->vx = (np->d*np->d );
	   bp->vy = np->km; }
	if( np == np->next ) return 1;
	np = np->next;
	}
	return 0;
}
int v_ho_noel( V, lambda )
	float *V,lambda;
{
	NOEL *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	float hol,get_f_variable(),target;
	hol = get_f_variable("lambda");
	if( hol > 1.) hol = 1.;
	if( hol < 0.) hol = 0.;
	bp = noel_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active ){
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r);
	if( r < bp->d -bp->dm)
	{
	target = hol*r + (1.-hol)*(bp->d-bp->dm);
	r = r - target;
	*V += bp->km * r*r;
	} else if( r > bp->d+ bp->dh) {
	target = hol*r + (1.-hol)*(bp->d+bp->dh);
	r = r - target;
	*V += bp->kh * r*r;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_ho_noel(lambda)
float lambda;
{
	NOEL *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	float hol,get_f_variable(),target;
	hol = get_f_variable("lambda");
	if( hol > 1.) hol = 1.;
	if( hol < 0.) hol = 0.;
	bp = noel_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( a1->active || a2->active){
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	if( r < bp->d -bp->dm)
	{
	target = hol*r + (1.-hol)*(bp->d-bp->dm);
	r = r - target;
	ux = 2*bp->km * r*(1.-hol) *ux;
	uy = 2*bp->km * r*(1.-hol) *uy;
	uz = 2*bp->km * r*(1.-hol) *uz;
	} else if( r > bp->d+ bp->dh) {
	target = hol*r + (1.-hol)*(bp->d+bp->dh);
	r = r - target;
	ux = 2*bp->kh * r*(1.-hol) *ux;
	uy = 2*bp->kh * r*(1.-hol) *uy;
	uz = 2*bp->kh * r*(1.-hol) *uz;
	}else{
	ux = 0.; uy = 0.; uz = 0.;
	}
	if( a1->active){
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	}
	if( a2->active) {
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	}
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
/* 当前文件是D:\Read\optimist.c*/

#define ANSI 1
#ifdef ANSI
#endif
int a_f_zero();
int a_ftodx(float,float);
int steep( vfs,ffs,nfs, nstep,toler )
int nfs,(*vfs[])(),(*ffs[])();
int nstep;
float toler;
{
	int i,j,ifs;
	float vb,vt,vto;
	float a_max_f(),lam;
	for( i=0; i< nstep ; i++)
	{
	vb = 0.;
	for( ifs = 0; ifs < nfs; ifs++)
		(*vfs[ifs])( &vb,  0.);
	a_f_zero();
	for( ifs = 0; ifs < nfs; ifs++)
		(*ffs[ifs])( 0.);
	lam = a_max_f();
	if( lam <= toler) return 1;
	if( lam <= 1. )
	{ a_ftodx(1.,0.); } else { a_ftodx( 1./sqrt(lam),0. ); }
	vto = vb;
	lam = 0.;
	for( j=0; j< 200; j++)
	{
		vt = 0.;
		 lam = lam + .01*j;
		for( ifs = 0; ifs < nfs; ifs++)
		       (*vfs[ifs])(&vt, lam);
		if( vt > vto && j == 0 )
		{ a_ftodx(0., .1);   }
		else if( vt > vto )
		{ lam = lam -.01*j; break; }
		vto = vt;
	}
	a_inc_d( lam );
	}
	return 0;
}
int cngdel( vfs,ffs,nfs, nstep,nreset,toler,echo )
int nfs,(*vfs[])(),(*ffs[])();
int nstep,nreset;
float toler;
{
int a_f_zero();
int a_ftodx(float,float);
	int i,j,ifs;
	float vb,vt,vto;
	float a_max_f(),lam;
	float linmin(),a_max_d();
	float a_pr_beta();
	float beta,betad,a_l2_f(),a_l2_g();
	if( nreset < 1) nreset = nstep;
	a_g_zero();
	a_d_zero();
	for( i=0; i< nstep ; i++)
	{
	vb = 0.;
	for( ifs = 0; ifs < nfs; ifs++)
		(*vfs[ifs])( &vb,  0.);
	a_f_zero();
	for( ifs = 0; ifs < nfs; ifs++)
		(*ffs[ifs])( 0.);
	lam = a_max_f();
	beta = a_pr_beta();
	if( (i%nreset) == 0) beta = 0.;
	if( echo) printf(" vb, maxf %f %f %f \n",vb,lam,beta);
	if( lam <= toler) return 1;
	lam = a_max_f();
	 a_ftodx(1.,beta);
	a_ftogx( 1.,0.);
	lam = linmin( vfs,nfs, sqrt(a_max_d()) );
if( lam < 1.e-6)
{
a_f_zero();
for( ifs = 0; ifs < nfs; ifs++)
(*ffs[ifs])(0. );
lam = sqrt(a_max_f()); if( lam < 1.) lam = 1.;
a_ftodx( 1./(lam), 0.);
lam = linmin(vfs,nfs,1. );
if( lam < 1.e-6) return 0;
}
	a_inc_d( lam );
	}
	return 0;
}
float linmin(ffs,nfs ,damp )
int (*ffs[])();
int nfs;
float damp;
{
	int i,iter,jter,imin;
	float alpha[401],fval[401],dstep,step,stpmin,fvt,fmin,fold;
	int nostep,get_i_variable();
	float mxdq, get_f_variable();
	nostep = get_i_variable("nostep");
	if( nostep < 1) nostep = 8;
	mxdq = get_f_variable("mxdq");
	set_f_variable("mxdq" , 100.);
	
	dstep = 1.;
	step = 0;
	stpmin = 0.;
	imin = 0;
	alpha[0] = 0;
	fval[0] = 0;
	 if( damp < 1.) {dstep = .25;}else{ dstep = 1./damp;}
	for( i=0; i< nfs ; i++)	
	 (*ffs[i])(&fval[0],0.);
	fmin = fval[0]; fold = fmin;
	imin++;
recheck:
	alpha[imin] = dstep;
	fval[imin] = 0.;
	for( i=0; i< nfs ; i++)	
	 (*ffs[i])(&fval[imin],dstep);
	if( fval[imin] > fval[0])
		{
		    dstep = dstep*.25;
			if( dstep > 1.e-8) goto recheck;
			goto cleanup;
		}
	for( iter=0; iter< nostep; iter++)
	{
		for(jter=1; jter<100; jter++)
		{
			step += dstep;
			for( i=0; i< imin; i++)
			{
				if( alpha[i] == step)
				{
					fvt = fval[i]; goto FOUND ;
				}
			}
		fvt = 0.;
		for( i=0; i< nfs ; i++)	
			 (*ffs[i])(&fvt,step);
			alpha[imin] = step;  fval[imin++] = fvt;
			if( imin > 400) imin = 400;
FOUND:
			if( fvt< fmin)
			{
				fmin = fvt; stpmin = step;
			}
			if( fvt > fold)
			{
				dstep = -dstep/2; break;
			}
			fold = fvt;
		}
		
	}
cleanup:
	set_f_variable("mxdq" , mxdq);
	return(stpmin);
}
/* 当前文件是D:\Read\random.c*/

float randf()
{
	static float buff[55];
	static int ip = 0,jp = 0,kp;
	int i,seed,get_i_variable();
	 float xva;
	if( ip == 0 && jp == 0)
	{
	seed = get_i_variable("seed");
	for( ip=0; ip < 55; ip++)
	    { seed = (seed*2349+14867)%32767;
		buff[ip] = (float)seed/32767.;
		if( buff[ip] > 1.) buff[ip] = buff[ip]-1.;
		if( buff[ip] < 0.) buff[ip] = buff[ip]+1.;
		}
	ip = 24; jp=55-ip; kp = 0;
	}
	i = kp;
	xva = buff[jp]+buff[ip];
	if( xva > 1.) xva = xva -1.;
	buff[kp] = xva;
	kp = (kp+1)%55;
	ip = (ip+1)%55;
	jp = (jp+1)%55;
	return buff[i];
}
float randg()
{
	float randf();
	float x1,x2,norm;
	
	norm = 2.;
	while( norm > 1.)
	{
		x1 = 2.*randf()-1; x2 = 2.*randf()-1;
		norm = x1*x1 + x2*x2;
	}
	if( norm < 1.e-9) norm = 1.e-9;
	return x1*sqrt( -2.*log(norm)/norm );
}
void rand3( float *x, float *y, float *z )
{
	float randf();
	float alpha,norm,x1,x2;
	norm = 2.;
	while( norm > 1.)
	{
		x1 = 2.*randf()-1; x2 = 2.*randf()-1;
		norm = x1*x1 + x2*x2;
	}
	*x = x1; *y = x2;
	norm = sqrt(1.-norm);
	*z = norm;
	if( randf() < 0.5) *z = -norm;
}
/* 当前文件是D:\Read\rectmm.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct {
float xc,yc,zc;
float sqp;
float sa,xa,ya,za;
float q100,q010,q001;
float q200,q020,q002,q110,q101,q011;
float q300,q030,q003,q210,q201,q120,q021,q102,q012,q111;
#ifdef FOURTH
float q400,q040,q004,q310,q301,q130,q031,q103,q013,q220,q202,q022,q211,q121,q112;
#endif
#ifdef FIFTH
float q500,q050,q005,q410,q401,q140,q041,q104,q014,q320,q230,q302,q203,q032,q023,q311,q131,q113,q221,q212,q122;
#endif
int first,last,innode; } MMNODE;
typedef struct {
ATOM *who;
int next,which; } MMATOM;
int mm_fv_update_nonbon(  lambda )
	float lambda;
{
	float r,r0,xt,yt,zt;
	float xt2,xt3,xt4,yt2,yt3,yt4,zt2,zt3,zt4;
	float k,k1,k2,k3,k4,k5;
	float ka2,ka3;
	float kb2,kb3;
	float c1,c2,c3,c4,c5;
	float get_f_variable();
	int inbond,inangle,i;
	ATOM *ap,*a1,*a2,*bonded[10],*angled[10];
	ATOM *a_next( );
	int a_number();
	int ii,j,jj,imax,inclose;
	float (*vector)[];
	ATOM *close[NCLOSE],*(*atomall)[];
	float mxdq,dielectric,mxcut;
	float mmbox;
	float xmax,xmin,ymax,ymin,zmax,zmin;
	int nx,ny,nz;
	int ix,iy,iz,inode;
	int naybor[27];
	char line[80];
	MMNODE (*nodelist)[];
	MMATOM (*atomlist)[];
	mmbox = get_f_variable("mmbox");
	mxcut = get_f_variable("mxcut");
	if( mxcut < 0.) mxcut= 5.;
	dielectric = get_f_variable("dielec");
	if( dielectric <= 0.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	
	i = a_number();
	vector = malloc( 4*i*sizeof(float) );
	if( vector == NULL)
	{ aaerror("cannot allocate memory in mm_fv_update\n"); return 0;}
	atomall = malloc( i*sizeof(ATOM *) );
	if( atomall == NULL)
	{aaerror("cannot allocate memory in mm_fv_update\n"); return 0;}
	atomlist = malloc( i * sizeof( MMATOM ));
	if( atomlist == NULL)
	{ aaerror("cannot allocate memory in mm_fv_update\n"); return 0;}
	imax = a_number();
	jj = imax;
	for( i=0; i< imax; i++)
	{
		(*atomall)[i] = a_next(i);
		(*atomlist)[i].who = (*atomall)[i];
	}
	for( ii=0; ii< imax; ii++)
	{
a1 = (*atomall)[ii];
	j = ii*4;
(*vector)[j] = a1->dx*lambda +a1->x ;
(*vector)[j+1] = a1->dy*lambda +a1->y;
(*vector)[j+2] = a1->dz*lambda +a1->z;
	}
	xmax = -10e10;
	ymax = -10e10;
	zmax = -10e10;
	xmin =  10e10;
	ymin =  10e10;
	zmin =  10e10;
	for( ii= 0; ii< imax; ii++)
	{
		j = ii*4;
	  if( xmax < (*vector)[j] ) xmax = (*vector)[j];
	  if( ymax < (*vector)[j+1] ) ymax = (*vector)[j+1];
	  if( zmax < (*vector)[j+2] ) zmax = (*vector)[j+2];
	  if( xmin > (*vector)[j] ) xmin = (*vector)[j];
	  if( ymin > (*vector)[j+1] ) ymin = (*vector)[j+1];
	  if( zmin > (*vector)[j+2] ) zmin = (*vector)[j+2];
	  }
	nx = (xmax - xmin)/mmbox + 1 ;
	ny = (ymax - ymin)/mmbox + 1 ;
	nz = (zmax - zmin)/mmbox + 1 ;
	nodelist = malloc( nx*ny*nz * sizeof( MMNODE ));
	if( nodelist == NULL)
	{ aaerror("cannot allocate node memory in mm_fv_update (doubling grid )\n");
	sprintf(line,"mmbox %f nx %d ny %d nz %d ",mmbox,nx,ny,nz);
	aaerror( line);
	sprintf(line," xmin xmax %f %f ymin ymax %f %f zmin zmax %f %f",
	xmin,xmax,ymin,ymax,zmin,zmax);
	aaerror( line);
	mmbox = mmbox *2;
	set_f_variable( "mmbox",mmbox);
	nx = (xmax - xmin)/mmbox + 1;
	ny = (ymax - ymin)/mmbox + 1;
	nz = (zmax - zmin)/mmbox + 1;
	nodelist = malloc( nx*ny*nz * sizeof( MMNODE ));
	if( nodelist == NULL)
	{ aaerror("cannot allocate node memory in mm_fv_update (cannot do it)\n"); return 0; }
	}
	for( ix=0; ix< nx; ix++)
	for( iy=0; iy< ny; iy++)
	for( iz=0; iz< nz; iz++)
	{
	inode = ((iz*ny)+iy)*nx + ix;
	(*nodelist)[inode].xc = ix*mmbox + .5*mmbox + xmin;
	(*nodelist)[inode].yc = iy*mmbox + .5*mmbox + ymin;
	(*nodelist)[inode].zc = iz*mmbox + .5*mmbox + zmin;
	}
	for( ii=0; ii < nx*ny*nz; ii++)
	{
	(*nodelist)[ii].sqp = 0.;
	(*nodelist)[ii].sa = 0.;
	(*nodelist)[ii].xa = 0.;
	(*nodelist)[ii].ya = 0.;
	(*nodelist)[ii].za = 0.;
	(*nodelist)[ii].q100 = 0.;
	(*nodelist)[ii].q010 = 0.;
	(*nodelist)[ii].q001 = 0.;
	(*nodelist)[ii].q200 = 0.;
	(*nodelist)[ii].q020 = 0.;
	(*nodelist)[ii].q002 = 0.;
	(*nodelist)[ii].q101 = 0.;
	(*nodelist)[ii].q110 = 0.;
	(*nodelist)[ii].q011 = 0.;
	(*nodelist)[ii].q300 = 0.;
	(*nodelist)[ii].q030 = 0.;
	(*nodelist)[ii].q003 = 0.;
	(*nodelist)[ii].q210 = 0.;
	(*nodelist)[ii].q120 = 0.;
	(*nodelist)[ii].q201 = 0.;
	(*nodelist)[ii].q102 = 0.;
	(*nodelist)[ii].q021 = 0.;
	(*nodelist)[ii].q012 = 0.;
	(*nodelist)[ii].q111 = 0.;
#ifdef FOURTH
	(*nodelist)[ii].q400 = 0.;
	(*nodelist)[ii].q040 = 0.;
	(*nodelist)[ii].q004 = 0.;
	(*nodelist)[ii].q310 = 0.;
	(*nodelist)[ii].q130 = 0.;
	(*nodelist)[ii].q301 = 0.;
	(*nodelist)[ii].q103 = 0.;
	(*nodelist)[ii].q031 = 0.;
	(*nodelist)[ii].q013 = 0.;
	(*nodelist)[ii].q220 = 0.;
	(*nodelist)[ii].q202 = 0.;
	(*nodelist)[ii].q022 = 0.;
	(*nodelist)[ii].q211 = 0.;
	(*nodelist)[ii].q121 = 0.;
	(*nodelist)[ii].q112 = 0.;
#endif
#ifdef FIFTH
	(*nodelist)[ii].q500 = 0.;
	(*nodelist)[ii].q050 = 0.;
	(*nodelist)[ii].q005 = 0.;
	(*nodelist)[ii].q410 = 0.;
	(*nodelist)[ii].q140 = 0.;
	(*nodelist)[ii].q401 = 0.;
	(*nodelist)[ii].q104 = 0.;
	(*nodelist)[ii].q041 = 0.;
	(*nodelist)[ii].q014 = 0.;
	(*nodelist)[ii].q320 = 0.;
	(*nodelist)[ii].q230 = 0.;
	(*nodelist)[ii].q302 = 0.;
	(*nodelist)[ii].q203 = 0.;
	(*nodelist)[ii].q032 = 0.;
	(*nodelist)[ii].q023 = 0.;
	(*nodelist)[ii].q221 = 0.;
	(*nodelist)[ii].q212 = 0.;
	(*nodelist)[ii].q122 = 0.;
	(*nodelist)[ii].q311 = 0.;
	(*nodelist)[ii].q131 = 0.;
	(*nodelist)[ii].q113 = 0.;
#endif
	(*nodelist)[ii].first = -1;
	(*nodelist)[ii].last = -1;
	(*nodelist)[ii].innode = 0;
	}
	
	for( ii=0; ii< imax; ii++)
	{
	j = ii*4;
	ix = ((*vector)[j] - xmin )/mmbox;
	iy = ((*vector)[j+1] - ymin )/mmbox;
	iz = ((*vector)[j+2] - zmin )/mmbox;
	inode = ((iz*ny)+iy)*nx + ix;
	(*atomlist)[ii].which = inode;
	}
	for( inode = 0; inode < nx*ny*nz; inode++)
	{
	
	for( ii = 0; ii< imax; ii++)
	{
		if( (*atomlist)[ii].which == inode)
		{
		(*nodelist)[inode].first = ii;
		(*nodelist)[inode].last = ii;
		(*nodelist)[inode].innode += 1;
		ap = (*atomlist)[ii].who;
		break;
		}
	}
	
	if( ii != imax )
	{
	for( ii= (*nodelist)[inode].first; ii < imax; ii++)
	{
		if( (*atomlist)[ii].which == inode)
		{
		(*atomlist)[(*nodelist)[inode].last].next  = ii;
		(*nodelist)[inode].last = ii;
		(*nodelist)[inode].innode += 1;
		ap = (*atomlist)[ii].who;
		xt = ap->x + lambda*ap->dx - (*nodelist)[inode].xc;
		yt = ap->y + lambda*ap->dy - (*nodelist)[inode].yc;
		zt = ap->z + lambda*ap->dz - (*nodelist)[inode].zc;
		(*nodelist)[inode].sqp +=  ap->q;
		(*nodelist)[inode].sa +=  ap->a;
		(*nodelist)[inode].xa +=  ap->a*xt;
		(*nodelist)[inode].ya +=  ap->a*yt;
		(*nodelist)[inode].za +=  ap->a*zt;
		xt2 = xt*xt;
		xt3 = xt2*xt;
		xt4 = xt3*xt;
		yt2 = yt*yt;
		yt3 = yt2*yt;
		yt4 = yt3*yt;
		zt2 = zt*zt;
		zt3 = zt2*zt;
		zt4 = zt3*zt;
	(*nodelist)[inode].q100 += ap->q*xt;
	(*nodelist)[inode].q010 += ap->q*yt;
	(*nodelist)[inode].q001 += ap->q*zt;
	(*nodelist)[inode].q200 += ap->q*xt2;
	(*nodelist)[inode].q020 += ap->q*yt2;
	(*nodelist)[inode].q002 += ap->q*zt2;
	(*nodelist)[inode].q101 += ap->q*xt*zt;
	(*nodelist)[inode].q110 += ap->q*xt*yt;
	(*nodelist)[inode].q011 += ap->q*yt*zt;
	(*nodelist)[inode].q300 += ap->q*xt3;
	(*nodelist)[inode].q030 += ap->q*yt3;
	(*nodelist)[inode].q003 += ap->q*zt3;
	(*nodelist)[inode].q210 += ap->q*xt2*yt;
	(*nodelist)[inode].q120 += ap->q*xt*yt2;
	(*nodelist)[inode].q201 += ap->q*xt2*zt;
	(*nodelist)[inode].q102 += ap->q*xt*zt2;
	(*nodelist)[inode].q021 += ap->q*yt2*zt;
	(*nodelist)[inode].q012 += ap->q*yt*zt2;
	(*nodelist)[inode].q111 += ap->q*xt*yt*zt;
#ifdef FOURTH
	(*nodelist)[inode].q400 += ap->q*xt4;
	(*nodelist)[inode].q040 += ap->q*yt4;
	(*nodelist)[inode].q004 += ap->q*zt4;
	(*nodelist)[inode].q310 += ap->q*xt3*yt;
	(*nodelist)[inode].q130 += ap->q*xt*yt3;
	(*nodelist)[inode].q301 += ap->q*xt3*zt;
	(*nodelist)[inode].q103 += ap->q*xt*zt3;
	(*nodelist)[inode].q031 += ap->q*yt3*zt;
	(*nodelist)[inode].q013 += ap->q*yt*zt3;
	(*nodelist)[inode].q220 += ap->q*xt2*yt2;
	(*nodelist)[inode].q202 += ap->q*xt2*zt2;
	(*nodelist)[inode].q022 += ap->q*yt2*zt2;
	(*nodelist)[inode].q211 += ap->q*xt2*yt*zt;
	(*nodelist)[inode].q121 += ap->q*xt*yt2*zt;
	(*nodelist)[inode].q112 += ap->q*xt*yt*zt2;
#endif
#ifdef FIFTH
	(*nodelist)[inode].q500 += ap->q*xt4*xt;
	(*nodelist)[inode].q050 += ap->q*yt4*yt;
	(*nodelist)[inode].q005 += ap->q*zt4*zt;
	(*nodelist)[inode].q410 += ap->q*xt4*yt;
	(*nodelist)[inode].q140 += ap->q*yt4*xt;
	(*nodelist)[inode].q401 += ap->q*xt4*zt;
	(*nodelist)[inode].q104 += ap->q*zt4*xt;
	(*nodelist)[inode].q041 += ap->q*yt4*zt;
	(*nodelist)[inode].q014 += ap->q*zt4*yt;
	(*nodelist)[inode].q320 += ap->q*xt3*yt2;
	(*nodelist)[inode].q230 += ap->q*yt3*xt2;
	(*nodelist)[inode].q302 += ap->q*xt3*zt2;
	(*nodelist)[inode].q203 += ap->q*zt3*xt2;
	(*nodelist)[inode].q032 += ap->q*yt3*zt2;
	(*nodelist)[inode].q023 += ap->q*zt3*yt2;
	(*nodelist)[inode].q221 += ap->q*xt2*yt2*zt;
	(*nodelist)[inode].q212 += ap->q*xt2*yt*zt2;
	(*nodelist)[inode].q122 += ap->q*xt*yt2*zt2;
	(*nodelist)[inode].q311 += ap->q*xt3*yt*zt;
	(*nodelist)[inode].q131 += ap->q*xt*yt3*zt;
	(*nodelist)[inode].q113 += ap->q*xt*yt*zt3;
#endif
		}
	}
	}
	}
	
	k = dielectric *.5;
	xt = .5/3.;
	yt = xt/4.;
	zt = yt/5.;
	for( ii = 0; ii < nx*ny*nz; ii ++)
	{
	(*nodelist)[ii].sqp *= k;
	(*nodelist)[ii].q100 *= k;
	(*nodelist)[ii].q010 *= k;
	(*nodelist)[ii].q001 *= k;
	(*nodelist)[ii].q200 *= .5*k;
	(*nodelist)[ii].q020 *= .5*k;
	(*nodelist)[ii].q002 *= .5*k;
	(*nodelist)[ii].q101 *= k;
	(*nodelist)[ii].q110 *= k;
	(*nodelist)[ii].q011 *= k;
	(*nodelist)[ii].q300 *= xt*k;
	(*nodelist)[ii].q030 *= xt*k;
	(*nodelist)[ii].q003 *= xt*k;
	(*nodelist)[ii].q210 *= 0.5*k;
	(*nodelist)[ii].q120 *= 0.5*k;
	(*nodelist)[ii].q201 *= 0.5*k;
	(*nodelist)[ii].q102 *= 0.5*k;
	(*nodelist)[ii].q021 *= 0.5*k;
	(*nodelist)[ii].q012 *= 0.5*k;
	(*nodelist)[ii].q111 *= k;
#ifdef FOURTH
	(*nodelist)[ii].q400 *= yt*k;
	(*nodelist)[ii].q040 *= yt*k;
	(*nodelist)[ii].q004 *= yt*k;
	(*nodelist)[ii].q310 *= xt*k;
	(*nodelist)[ii].q130 *= xt*k;
	(*nodelist)[ii].q301 *= xt*k;
	(*nodelist)[ii].q103 *= xt*k;
	(*nodelist)[ii].q031 *= xt*k;
	(*nodelist)[ii].q013 *= xt*k;
	(*nodelist)[ii].q220 *= .25*k;
	(*nodelist)[ii].q202 *= .25*k;
	(*nodelist)[ii].q022 *= .25*k;
	(*nodelist)[ii].q211 *= .5*k;
	(*nodelist)[ii].q121 *= .5*k;
	(*nodelist)[ii].q112 *= .5*k;
#endif
#ifdef FIFTH
	(*nodelist)[ii].q500 *= zt*k;
	(*nodelist)[ii].q050 *= zt*k;
	(*nodelist)[ii].q005 *= zt*k;
	(*nodelist)[ii].q410 *= yt*k;
	(*nodelist)[ii].q140 *= yt*k;
	(*nodelist)[ii].q401 *= yt*k;
	(*nodelist)[ii].q104 *= yt*k;
	(*nodelist)[ii].q041 *= yt*k;
	(*nodelist)[ii].q014 *= yt*k;
	(*nodelist)[ii].q320 *= .5*xt*k;
	(*nodelist)[ii].q230 *= .5*xt*k;
	(*nodelist)[ii].q302 *= .5*xt*k;
	(*nodelist)[ii].q203 *= .5*xt*k;
	(*nodelist)[ii].q032 *= .5*xt*k;
	(*nodelist)[ii].q023 *= .5*xt*k;
	(*nodelist)[ii].q221 *= .25*k;
	(*nodelist)[ii].q212 *= .25*k;
	(*nodelist)[ii].q122 *= .25*k;
	(*nodelist)[ii].q311 *= xt*k;
	(*nodelist)[ii].q131 *= xt*k;
	(*nodelist)[ii].q113 *= xt*k;
#endif
	
	if( (*nodelist)[ii].sa != 0.)
	{
	(*nodelist)[ii].xa = (*nodelist)[ii].xa/(*nodelist)[ii].sa;
	(*nodelist)[ii].ya = (*nodelist)[ii].ya/(*nodelist)[ii].sa;
	(*nodelist)[ii].za = (*nodelist)[ii].za/(*nodelist)[ii].sa;
	}
	(*nodelist)[ii].xa += (*nodelist)[ii].xc;
	(*nodelist)[ii].ya += (*nodelist)[ii].yc;
	(*nodelist)[ii].za += (*nodelist)[ii].zc;
	(*nodelist)[ii].sa  *= .5;
	}
	for( ii=0; ii< jj; ii++)
	{
	a1 = (*atomall)[ii];
	a1-> px = a1->x + lambda*a1->dx;
	a1-> py = a1->y + lambda*a1->dy;
	a1-> pz = a1->z + lambda*a1->dz;
	a1 -> VP = 0.;
	a1 -> dpx = 0.;
	a1 -> dpy = 0.;
	a1 -> dpz = 0.;
	a1 -> qxx = 0.;
	a1 -> qxy = 0.;
	a1 -> qxz = 0.;
	a1 -> qyy = 0.;
	a1 -> qyz = 0.;
	a1 -> qzz = 0.;
#ifdef CUBIC
	a1 -> qxxx = 0.;
	a1 -> qxxy = 0.;
	a1 -> qxxz = 0.;
	a1 -> qxyy = 0.;
	a1 -> qxyz = 0.;
	a1 -> qxzz = 0.;
	a1 -> qyyy = 0.;
	a1 -> qyyz = 0.;
	a1 -> qyzz = 0.;
	a1 -> qzzz = 0.;
#endif
	for( j=0; j< NCLOSE; j++)
		a1->close[j] = NULL;
	}
	for( ii=0; ii<  jj; ii++)
	{
	a1 = (*atomlist)[ii].who;
	inclose = 0;
	ix = (a1->px  - xmin )/mmbox ;
	iy = (a1->py  - ymin )/mmbox ;
	iz = (a1->pz  - zmin )/mmbox ;
	naybor[0] = ((iz*ny)+iy)*nx + ix;
	naybor[1] = ((iz*ny)+iy)*nx + ix+1;
	naybor[2] = ((iz*ny)+iy)*nx + ix-1;
	naybor[3] = ((iz*ny)+iy)*nx+nx + ix;
	naybor[4] = ((iz*ny)+iy)*nx-nx + ix;
	naybor[5] = ((iz*ny)+iy)*nx+nx + ix+1;
	naybor[6] = ((iz*ny)+iy)*nx+nx + ix-1;
	naybor[7] = ((iz*ny)+iy)*nx-nx + ix+1;
	naybor[8] = ((iz*ny)+iy)*nx-nx + ix-1;
	naybor[9] = ((iz*ny)+ny+iy)*nx + ix;
	naybor[10] = ((iz*ny)+ny+iy)*nx + ix+1;
	naybor[11] = ((iz*ny)+ny+iy)*nx + ix-1;
	naybor[12] = ((iz*ny)+ny+iy)*nx+nx + ix;
	naybor[13] = ((iz*ny)+ny+iy)*nx-nx + ix;
	naybor[14] = ((iz*ny)+ny+iy)*nx+nx + ix+1;
	naybor[15] = ((iz*ny)+ny+iy)*nx+nx + ix-1;
	naybor[16] = ((iz*ny)+ny+iy)*nx-nx + ix+1;
	naybor[17] = ((iz*ny)+ny+iy)*nx-nx + ix-1;
	naybor[18] = ((iz*ny)-ny+iy)*nx + ix;
	naybor[19] = ((iz*ny)-ny+iy)*nx + ix+1;
	naybor[20] = ((iz*ny)-ny+iy)*nx + ix-1;
	naybor[21] = ((iz*ny)-ny+iy)*nx+nx + ix;
	naybor[22] = ((iz*ny)-ny+iy)*nx-nx + ix;
	naybor[23] = ((iz*ny)-ny+iy)*nx+nx + ix+1;
	naybor[24] = ((iz*ny)-ny+iy)*nx+nx + ix-1;
	naybor[25] = ((iz*ny)-ny+iy)*nx-nx + ix+1;
	naybor[26] = ((iz*ny)-ny+iy)*nx-nx + ix-1;
	for( inode = 0; inode < nx*ny*nz; inode ++)
	{
	
	for(j=0; j< 27; j++)
	{
	if( inode == naybor[j]) break; }
	if( j == 27  )
	{
	if( (*nodelist)[inode].innode > 0 )
	{
	
	xt = (*nodelist)[inode].xc - a1->px;
	yt = (*nodelist)[inode].yc - a1->py;
	zt = (*nodelist)[inode].zc - a1->pz;
	r = one/(xt*xt + yt*yt + zt*zt);
	r0 = sqrt(r);
	c1 =  -r*r0;
	c2 = -three*c1*r;
	c3 = -five*c2*r;
	c4 = -seven*c3*r;
	c5 = -nine*c4*r;
	xt2 = xt*xt;
	xt3 = xt2*xt;
	xt4 = xt3*xt;
	yt2 = yt*yt;
	yt3 = yt2*yt;
	yt4 = yt3*yt;
	zt2 = zt*zt;
	zt3 = zt2*zt;
	zt4 = zt3*zt;
	a1->VP += (*nodelist)[inode].sqp*a1->q*r0;
	k = c1*a1->q*xt;
	a1->VP += k*(*nodelist)[inode].q100;
	a1->dpx += k*(*nodelist)[inode].sqp;
	k = c1*a1->q*yt;
	a1->VP += k*(*nodelist)[inode].q010;
	a1->dpy += k*(*nodelist)[inode].sqp;
	k = c1*a1->q*zt;
	a1->VP += k*(*nodelist)[inode].q001;
	a1->dpz += k*(*nodelist)[inode].sqp;
	k = (c2*xt2 +c1)*a1->q;
	a1->VP += k*(*nodelist)[inode].q200;
	a1->dpx += k*(*nodelist)[inode].q100;
	a1->qxx += k*(*nodelist)[inode].sqp;
	k = (c2*yt2 +c1)*a1->q;
	a1->VP += k*(*nodelist)[inode].q020;
	a1->dpy += k*(*nodelist)[inode].q010;
	a1->qyy += k*(*nodelist)[inode].sqp;
	k = (c2*zt2 +c1)*a1->q;
	a1->VP += k*(*nodelist)[inode].q002;
	a1->dpz += k*(*nodelist)[inode].q001;
	a1->qzz += k*(*nodelist)[inode].sqp;
	k = c2*xt*yt*a1->q;
	a1->VP += k*(*nodelist)[inode].q110;
	a1->dpx += k*(*nodelist)[inode].q010;
	a1->dpy += k*(*nodelist)[inode].q100;
	a1->qxy += k*(*nodelist)[inode].sqp;
	k = c2*xt*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q101;
	a1->dpx += k*(*nodelist)[inode].q001;
	a1->dpz += k*(*nodelist)[inode].q100;
	a1->qxz += k*(*nodelist)[inode].sqp;
	k = c2*yt*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q011;
	a1->dpy += k*(*nodelist)[inode].q001;
	a1->dpz += k*(*nodelist)[inode].q010;
	a1->qyz += k*(*nodelist)[inode].sqp;
	k = (c3*xt3 +3*c2*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q300;
	a1->dpx += k*(*nodelist)[inode].q200;
	a1->qxx += k*(*nodelist)[inode].q100;
	k = (c3*yt3 +3*c2*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q030;
	a1->dpy += k*(*nodelist)[inode].q020;
	a1->qyy += k*(*nodelist)[inode].q010;
	k = (c3*zt3 +3*c2*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q003;
	a1->dpz += k*(*nodelist)[inode].q002;
	a1->qzz += k*(*nodelist)[inode].q001;
	k = (c3*xt2*yt+c2*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q210;
	a1->dpx += k*(*nodelist)[inode].q110;
	a1->dpy += k*(*nodelist)[inode].q200;
	a1->qxx += k*(*nodelist)[inode].q010;
	a1->qxy += k*(*nodelist)[inode].q100;
	k = (c3*yt2*xt+c2*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q120;
	a1->dpx += k*(*nodelist)[inode].q020;
	a1->dpy += k*(*nodelist)[inode].q110;
	a1->qyy += k*(*nodelist)[inode].q100;
	a1->qxy += k*(*nodelist)[inode].q010;
	k = (c3*xt2*zt+c2*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q201;
	a1->dpx += k*(*nodelist)[inode].q101;
	a1->dpz += k*(*nodelist)[inode].q200;
	a1->qxx += k*(*nodelist)[inode].q001;
	a1->qxz += k*(*nodelist)[inode].q100;
	k = (c3*zt2*xt+c2*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q102;
	a1->dpx += k*(*nodelist)[inode].q002;
	a1->dpz += k*(*nodelist)[inode].q101;
	a1->qzz += k*(*nodelist)[inode].q100;
	a1->qxz += k*(*nodelist)[inode].q001;
	k = (c3*yt2*zt+c2*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q021;
	a1->dpy += k*(*nodelist)[inode].q011;
	a1->dpz += k*(*nodelist)[inode].q020;
	a1->qyy += k*(*nodelist)[inode].q001;
	a1->qyz += k*(*nodelist)[inode].q010;
	k = (c3*zt2*yt+c2*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q012;
	a1->dpy += k*(*nodelist)[inode].q002;
	a1->dpz += k*(*nodelist)[inode].q011;
	a1->qzz += k*(*nodelist)[inode].q010;
	a1->qyz += k*(*nodelist)[inode].q001;
	k = (c3*zt*yt*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q111;
	a1->dpx += k*(*nodelist)[inode].q011;
	a1->dpy += k*(*nodelist)[inode].q101;
	a1->dpz += k*(*nodelist)[inode].q110;
#ifdef FOURTH
	k = (c4*xt4 +six*c3*(xt2) +three*c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q400;
	a1->dpx += k*(*nodelist)[inode].q300;
	a1->qxx += k*(*nodelist)[inode].q200;
	k = (c4*yt4 +six*c3*(yt2) +three*c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q040;
	a1->dpy += k*(*nodelist)[inode].q030;
	a1->qyy += k*(*nodelist)[inode].q020;
	k = (c4*zt4 +six*c3*(zt2) +three*c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q004;
	a1->dpz += k*(*nodelist)[inode].q003;
	a1->qzz += k*(*nodelist)[inode].q002;
	k = (c4*xt3*yt + three*c3*xt*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q310;
	a1->dpx += k*(*nodelist)[inode].q210;
	a1->dpy += k*(*nodelist)[inode].q300;
	a1->qxx += k*(*nodelist)[inode].q110;
	a1->qxy += k*(*nodelist)[inode].q200;
	k = (c4*yt3*xt + three*c3*xt*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q130;
	a1->dpx += k*(*nodelist)[inode].q030;
	a1->dpy += k*(*nodelist)[inode].q120;
	a1->qyy += k*(*nodelist)[inode].q110;
	a1->qxy += k*(*nodelist)[inode].q020;
	k = (c4*xt3*zt + three*c3*xt*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q301;
	a1->dpx += k*(*nodelist)[inode].q201;
	a1->dpz += k*(*nodelist)[inode].q300;
	a1->qxx += k*(*nodelist)[inode].q101;
	a1->qxz += k*(*nodelist)[inode].q200;
	k = (c4*zt3*yt + three*c3*xt*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q103;
	a1->dpx += k*(*nodelist)[inode].q003;
	a1->dpz += k*(*nodelist)[inode].q102;
	a1->qzz += k*(*nodelist)[inode].q101;
	a1->qxz += k*(*nodelist)[inode].q002;
	k = (c4*yt3*zt + three*c3*zt*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q031;
	a1->dpz += k*(*nodelist)[inode].q030;
	a1->dpy += k*(*nodelist)[inode].q021;
	a1->qyy += k*(*nodelist)[inode].q011;
	a1->qyz += k*(*nodelist)[inode].q020;
	k = (c4*zt3*yt + three*c3*zt*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q013;
	a1->dpz += k*(*nodelist)[inode].q012;
	a1->dpy += k*(*nodelist)[inode].q003;
	a1->qzz += k*(*nodelist)[inode].q011;
	a1->qyz += k*(*nodelist)[inode].q002;
	k = (c4*xt2*yt2 + c3*(xt2+yt2) +c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q220;
	a1->dpx += k*(*nodelist)[inode].q120;
	a1->dpy += k*(*nodelist)[inode].q210;
	a1->qxx += k*(*nodelist)[inode].q020;
	a1->qyy += k*(*nodelist)[inode].q200;
	a1->qxy += k*(*nodelist)[inode].q110;
	k = (c4*xt2*zt2 + c3*(xt2+zt2) +c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q202;
	a1->dpx += k*(*nodelist)[inode].q102;
	a1->dpz += k*(*nodelist)[inode].q201;
	a1->qxx += k*(*nodelist)[inode].q002;
	a1->qzz += k*(*nodelist)[inode].q200;
	a1->qxz += k*(*nodelist)[inode].q101;
	k = (c4*zt2*yt2 + c3*(zt2+yt2) +c2)*a1->q;
	a1->VP += k*(*nodelist)[inode].q022;
	a1->dpz += k*(*nodelist)[inode].q021;
	a1->dpy += k*(*nodelist)[inode].q012;
	a1->qzz += k*(*nodelist)[inode].q020;
	a1->qyy += k*(*nodelist)[inode].q002;
	a1->qyz += k*(*nodelist)[inode].q011;
	k = (c4*xt2*yt*zt +c3*yt*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q211;
	a1->dpz += k*(*nodelist)[inode].q210;
	a1->dpy += k*(*nodelist)[inode].q201;
	a1->dpx += k*(*nodelist)[inode].q111;
	a1->qxx += k*(*nodelist)[inode].q011;
	a1->qxy += k*(*nodelist)[inode].q101;
	a1->qyz += k*(*nodelist)[inode].q200;
	a1->qxz += k*(*nodelist)[inode].q110;
	k = (c4*xt*yt2*zt +c3*xt*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q121;
	a1->dpz += k*(*nodelist)[inode].q120;
	a1->dpy += k*(*nodelist)[inode].q111;
	a1->dpx += k*(*nodelist)[inode].q021;
	a1->qyy += k*(*nodelist)[inode].q101;
	a1->qxy += k*(*nodelist)[inode].q011;
	a1->qyz += k*(*nodelist)[inode].q110;
	a1->qxz += k*(*nodelist)[inode].q020;
	k = (c4*xt*yt*zt2 +c3*yt*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q112;
	a1->dpz += k*(*nodelist)[inode].q111;
	a1->dpy += k*(*nodelist)[inode].q102;
	a1->dpx += k*(*nodelist)[inode].q012;
	a1->qzz += k*(*nodelist)[inode].q110;
	a1->qxy += k*(*nodelist)[inode].q002;
	a1->qxz += k*(*nodelist)[inode].q011;
	a1->qyz += k*(*nodelist)[inode].q101;
#endif
#ifdef FIFTH
	k = ((c5*xt+9*c4)*xt4  +15*c3*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q500;
	a1->dpx += k*(*nodelist)[inode].q400;
	a1->qxx += k*(*nodelist)[inode].q300;
	k = ((c5*yt+9*c4)*yt4  +15*c3*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q050;
	a1->dpy += k*(*nodelist)[inode].q040;
	a1->qyy += k*(*nodelist)[inode].q030;
	k = ((c5*zt+9*c4)*zt4  +15*c3*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q005;
	a1->dpz += k*(*nodelist)[inode].q004;
	a1->qzz += k*(*nodelist)[inode].q003;
	k = (c5*xt4+six*c4*xt2 +three*c3)*yt*a1->q;
	a1->VP += k*(*nodelist)[inode].q410;
	a1->dpx += k*(*nodelist)[inode].q310;
	a1->dpy += k*(*nodelist)[inode].q400;
	a1->qxx += k*(*nodelist)[inode].q210;
	a1->qxy += k*(*nodelist)[inode].q300;
	k = (c5*yt4+six*c4*yt2 +three*c3)*xt*a1->q;
	a1->VP += k*(*nodelist)[inode].q140;
	a1->dpx += k*(*nodelist)[inode].q040;
	a1->dpy += k*(*nodelist)[inode].q130;
	a1->qyy += k*(*nodelist)[inode].q120;
	a1->qxy += k*(*nodelist)[inode].q030;
	k = (c5*xt4+six*c4*xt2 +three*c3)*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q401;
	a1->dpx += k*(*nodelist)[inode].q301;
	a1->dpz += k*(*nodelist)[inode].q400;
	a1->qxx += k*(*nodelist)[inode].q201;
	a1->qxz += k*(*nodelist)[inode].q300;
	k = (c5*zt4+six*c4*zt2 +three*c3)*xt*a1->q;
	a1->VP += k*(*nodelist)[inode].q104;
	a1->dpx += k*(*nodelist)[inode].q004;
	a1->dpz += k*(*nodelist)[inode].q103;
	a1->qzz += k*(*nodelist)[inode].q102;
	a1->qxz += k*(*nodelist)[inode].q003;
	k = (c5*yt4+six*c4*yt2 +three*c3)*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q041;
	a1->dpy += k*(*nodelist)[inode].q031;
	a1->dpz += k*(*nodelist)[inode].q040;
	a1->qyy += k*(*nodelist)[inode].q021;
	a1->qyz += k*(*nodelist)[inode].q030;
	k = (c5*zt4+six*c4*zt2 +three*c3)*yt*a1->q;
	a1->VP += k*(*nodelist)[inode].q014;
	a1->dpy += k*(*nodelist)[inode].q004;
	a1->dpz += k*(*nodelist)[inode].q013;
	a1->qzz += k*(*nodelist)[inode].q012;
	a1->qyz += k*(*nodelist)[inode].q003;
	k = (c5*xt3*yt2 +c4*(three*xt*yt2-xt3) +three*c3*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q320;
	a1->dpx += k*(*nodelist)[inode].q220;
	a1->dpy += k*(*nodelist)[inode].q310;
	a1->qxx += k*(*nodelist)[inode].q120;
	a1->qxy += k*(*nodelist)[inode].q210;
	a1->qyy += k*(*nodelist)[inode].q300;
	k = (c5*yt3*xt2 +c4*(three*yt*xt2-yt3) +three*c3*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q230;
	a1->dpx += k*(*nodelist)[inode].q130;
	a1->dpy += k*(*nodelist)[inode].q220;
	a1->qxx += k*(*nodelist)[inode].q030;
	a1->qxy += k*(*nodelist)[inode].q120;
	a1->qyy += k*(*nodelist)[inode].q210;
	k = (c5*xt3*zt2 +c4*(three*xt*zt2-xt3) +three*c3*xt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q302;
	a1->dpx += k*(*nodelist)[inode].q202;
	a1->dpz += k*(*nodelist)[inode].q301;
	a1->qxx += k*(*nodelist)[inode].q102;
	a1->qxz += k*(*nodelist)[inode].q201;
	a1->qzz += k*(*nodelist)[inode].q300;
	k = (c5*zt3*xt2 +c4*(three*zt*xt2-zt3) +three*c3*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q203;
	a1->dpx += k*(*nodelist)[inode].q103;
	a1->dpz += k*(*nodelist)[inode].q202;
	a1->qxx += k*(*nodelist)[inode].q003;
	a1->qxz += k*(*nodelist)[inode].q102;
	a1->qzz += k*(*nodelist)[inode].q201;
	k = (c5*yt3*zt2 +c4*(three*yt*zt2-yt3) +three*c3*yt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q032;
	a1->dpy += k*(*nodelist)[inode].q022;
	a1->dpz += k*(*nodelist)[inode].q031;
	a1->qyy += k*(*nodelist)[inode].q012;
	a1->qyz += k*(*nodelist)[inode].q021;
	a1->qzz += k*(*nodelist)[inode].q030;
	k = (c5*zt3*yt2 +c4*(three*zt*yt2-zt3) +three*c3*zt)*a1->q;
	a1->VP += k*(*nodelist)[inode].q023;
	a1->dpy += k*(*nodelist)[inode].q013;
	a1->dpz += k*(*nodelist)[inode].q022;
	a1->qyy += k*(*nodelist)[inode].q003;
	a1->qyz += k*(*nodelist)[inode].q012;
	a1->qzz += k*(*nodelist)[inode].q021;
	k = (c5*xt2*yt2 +c4*(xt2+yt2) +c3)*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q221;
	a1->dpx += k*(*nodelist)[inode].q121;
	a1->dpy += k*(*nodelist)[inode].q211;
	a1->dpz += k*(*nodelist)[inode].q220;
	a1->qxx += k*(*nodelist)[inode].q021;
	a1->qyy += k*(*nodelist)[inode].q201;
	a1->qxz += k*(*nodelist)[inode].q120;
	a1->qyz += k*(*nodelist)[inode].q210;
	k = (c5*xt2*zt2 +c4*(xt2+zt2) +c3)*yt*a1->q;
	a1->VP += k*(*nodelist)[inode].q212;
	a1->dpx += k*(*nodelist)[inode].q112;
	a1->dpy += k*(*nodelist)[inode].q202;
	a1->dpz += k*(*nodelist)[inode].q211;
	a1->qxx += k*(*nodelist)[inode].q012;
	a1->qzz += k*(*nodelist)[inode].q210;
	a1->qxz += k*(*nodelist)[inode].q111;
	a1->qyz += k*(*nodelist)[inode].q201;
	k = (c5*zt2*yt2 +c4*(zt2+yt2) +c3)*xt*a1->q;
	a1->VP += k*(*nodelist)[inode].q122;
	a1->dpx += k*(*nodelist)[inode].q022;
	a1->dpy += k*(*nodelist)[inode].q112;
	a1->dpz += k*(*nodelist)[inode].q121;
	a1->qzz += k*(*nodelist)[inode].q120;
	a1->qyy += k*(*nodelist)[inode].q102;
	a1->qxy += k*(*nodelist)[inode].q022;
	a1->qxz += k*(*nodelist)[inode].q022;
	k = (c5*xt3+three*c4*xt)*yt*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q311;
	a1->dpx += k*(*nodelist)[inode].q211;
	a1->dpy += k*(*nodelist)[inode].q301;
	a1->dpz += k*(*nodelist)[inode].q310;
	a1->qxx += k*(*nodelist)[inode].q211;
	a1->qxy += k*(*nodelist)[inode].q201;
	a1->qxz += k*(*nodelist)[inode].q210;
	k = (c5*yt3+three*c4*yt)*xt*zt*a1->q;
	a1->VP += k*(*nodelist)[inode].q131;
	a1->dpx += k*(*nodelist)[inode].q031;
	a1->dpy += k*(*nodelist)[inode].q121;
	a1->dpz += k*(*nodelist)[inode].q130;
	a1->qyy += k*(*nodelist)[inode].q111;
	a1->qxy += k*(*nodelist)[inode].q021;
	a1->qyz += k*(*nodelist)[inode].q120;
	k = (c5*zt3+three*c4*zt)*yt*xt*a1->q;
	a1->VP += k*(*nodelist)[inode].q113;
	a1->dpx += k*(*nodelist)[inode].q013;
	a1->dpy += k*(*nodelist)[inode].q103;
	a1->dpz += k*(*nodelist)[inode].q112;
	a1->qzz += k*(*nodelist)[inode].q111;
	a1->qyz += k*(*nodelist)[inode].q102;
	a1->qxz += k*(*nodelist)[inode].q012;
#endif
	}
	} else if( (*nodelist)[inode].innode > 0)
		{
	imax = 0;
	i = (*nodelist)[inode].first;
	 if( (*nodelist)[inode].innode > 0  &&
	    ((*atomlist)[i].who)->serial > a1->serial)
	 {  (*atomall)[imax++] = (*atomlist)[i].who;}
	for( j=1; j< (*nodelist)[inode].innode -1 ; j++)
	{
	 i = (*atomlist)[i].next;
	 if( ((*atomlist)[i].who)->serial > a1->serial)
	 {  (*atomall)[imax++] = (*atomlist)[i].who;}
	}
	
	for( i=0; i< imax; i++)
	{
	a2 = (*atomall)[i];
	j = i*4;
	(*vector)[j  ] = a2->px - a1->px ;
	(*vector)[j+1] = a2->py - a1->py ;
	(*vector)[j+2] = a2->pz - a1->pz ;
	}
	for( i=0; i< imax; i++)
	{
		j = i*4;
		(*vector)[j+3] = sqrt((*vector)[j]*(*vector)[j] +
				 (*vector)[j+1]*(*vector)[j+1] +
				 (*vector)[j+2]*(*vector)[j+2]);
	}
	for( i=0; i< imax; i++)
	{
	a2 = (*atomall)[i];
	for( j=0; j< a1->dontuse; j++)
	{ if( a2 == a1->excluded[j]) goto SKIPNEW;}
	j = i*4;
	if( (*vector)[j+3] > mxcut || inclose > NCLOSE )
	{
	r0 = one/(*vector)[j+3];
	r = r0*r0;
	r = r*r*r;
	xt = a1->q*a2->q*dielectric*r0;
	yt = a1->a*a2->a*r;
	zt = a1->b*a2->b*r*r;
	k = xt - yt + zt;
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	k1 = xt - yt*six + zt*twelve;
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	k2 = xt*three; ka2 = - yt*six*eight; kb2 =  zt*twelve*14;
#ifdef CUBIC
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	k3 = -xt*5*3; ka3 =   yt*6*8*10 ; kb3 =  -zt*12*14*16;
#endif
	k1 = -k1;
	xt = (*vector)[j]*r0 ;
	yt = (*vector)[j+1]*r0 ;
	zt = (*vector)[j+2] *r0;
	
	a1->VP += k;
	a2->dpx -= k1*xt;
	a1->dpx += k1*xt;
	a2->dpy -= k1*yt;
	a1->dpy += k1*yt;
	a2->dpz -= k1*zt;
	a1->dpz += k1*zt;
	xt2 = xt*xt; yt2 = yt*yt; zt2 = zt*zt;
	a2->qxx -= k2*(xt2 - third) + ka2*(xt2 - eightth)+kb2*(xt2-fourteenth) ;
	a1->qxx -= k2*(xt2 - third) + ka2*(xt2 - eightth)+kb2*(xt2-fourteenth) ;
	a2->qxy -= (k2+ka2+kb2)*yt*xt;
	a1->qxy -= (k2+ka2+kb2)*yt*xt;
	a2->qxz -= (k2+ka2+kb2)*zt*xt;
	a1->qxz -= (k2+ka2+kb2)*zt*xt;
	a2->qyy -= k2*(yt2 - third) + ka2*(yt2 - eightth)+kb2*(yt2-fourteenth) ;
	a1->qyy -= k2*(yt2 - third) + ka2*(yt2 - eightth)+kb2*(yt2-fourteenth) ;
	a2->qyz -= (k2+ka2+kb2)*yt*zt;
	a1->qyz -= (k2+ka2+kb2)*yt*zt;
	a2->qzz -= k2*(zt2 - third) + ka2*(zt2 - eightth)+kb2*(zt2-fourteenth) ;
	a1->qzz -= k2*(zt2 - third) + ka2*(zt2 - eightth)+kb2*(zt2-fourteenth) ;
#ifdef CUBIC
	a2->qxxx -= k3*(xt*xt*xt - xt*( 9./15 )) ;
	a2->qxxx -= ka3*(xt*xt*xt - xt*( 24./80 )) ;
	a2->qxxx -= kb3*(xt*xt*xt - xt*( 42./(14*18)));
	a1->qxxx += k3*(xt*xt*xt - xt*( 9./15 )) ;
	a1->qxxx += ka3*(xt*xt*xt - xt*( 24./80 )) ;
	a1->qxxx += kb3*(xt*xt*xt - xt*( 42./(14*18)));
	a2->qxxy -= k3*(yt*xt*xt - yt*( 6./ 15));
	a2->qxxy -= ka3*(yt*xt*xt - yt*( 11./ 80));
	a2->qxxy -= kb3*(yt*xt*xt - yt*( 17./ (14*18)));
	a1->qxxy += k3*(yt*xt*xt - yt*( 6./ 15));
	a1->qxxy += ka3*(yt*xt*xt - yt*( 11./ 80));
	a1->qxxy += kb3*(yt*xt*xt - yt*( 17./ (14*18)));
	a2->qxxz -= k3*(zt*xt*xt - zt*( 6./ 15));
	a2->qxxz -= ka3*(zt*xt*xt - zt*( 11./ 80));
	a2->qxxz -= kb3*(zt*xt*xt - zt*( 17./ (14*18)));
	a1->qxxz += k3*(zt*xt*xt - zt*( 6./ 15));
	a1->qxxz += ka3*(zt*xt*xt - zt*( 11./ 80));
	a1->qxxz += kb3*(zt*xt*xt - zt*( 17./ (14*18)));
	a2->qxyy -= k3*(yt*yt*xt - xt*( 6./ 15));
	a2->qxyy -= ka3*(yt*yt*xt - xt*( 11./ 80));
	a2->qxyy -= kb3*(yt*yt*xt - xt*( 17./ (14*18)));
	a1->qxyy += k3*(yt*yt*xt - xt*( 6./ 15));
	a1->qxyy += ka3*(yt*yt*xt - xt*( 11./ 80));
	a1->qxyy += kb3*(yt*yt*xt - xt*( 17./ (14*18)));
	a2->qxyz -= (k3+ka3+kb3)*yt*zt*xt;
	a1->qxyz += (k3+ka3+kb3)*yt*zt*xt;
	a2->qxzz -= k3*(zt*zt*xt - xt*( 6./ 15));
	a2->qxzz -= ka3*(zt*zt*xt - xt*( 11./ 80));
	a2->qxzz -= kb3*(zt*zt*xt - xt*( 17./ (14*18)));
	a1->qxzz += k3*(zt*zt*xt - xt*( 6./ 15));
	a1->qxzz += ka3*(zt*zt*xt - xt*( 11./ 80));
	a1->qxzz += kb3*(zt*zt*xt - xt*( 17./ (14*18)));
	a2->qyyy -= k3*(yt*yt*yt - yt*( 9./15 )) ;
	a2->qyyy -= ka3*(yt*yt*yt - yt*( 24./80 )) ;
	a2->qyyy -= kb3*(yt*yt*yt - yt*( 42./(14*18)));
	a1->qyyy += k3*(yt*yt*yt - yt*( 9./15 )) ;
	a1->qyyy += ka3*(yt*yt*yt - yt*( 24./80 )) ;
	a1->qyyy += kb3*(yt*yt*yt - yt*( 42./(14*18)));
	a2->qyyz -= k3*(yt*yt*zt - zt*( 6./ 15));
	a2->qyyz -= ka3*(yt*yt*zt - zt*( 11./ 80));
	a2->qyyz -= kb3*(yt*yt*zt - zt*( 17./ (14*18)));
	a1->qyyz += k3*(yt*yt*zt - zt*( 6./ 15));
	a1->qyyz += ka3*(yt*yt*zt - zt*(11./ 80));
	a1->qyyz += kb3*(yt*yt*zt - zt*( 17./ (14*18)));
	a2->qyzz -= k3*(zt*zt*yt - yt*( 6./ 15));
	a2->qyzz -= ka3*(zt*zt*yt - yt*( 11./ 80));
	a2->qyzz -= kb3*(zt*zt*yt - yt*( 17./ (14*18)));
	a1->qyzz += k3*(zt*zt*yt - yt*( 6./ 15));
	a1->qyzz += ka3*(zt*zt*yt - yt*( 11./ 80));
	a1->qyzz += kb3*(zt*zt*yt - yt*( 17./ (14*18)));
	a2->qzzz -= k3*(zt*zt*zt - zt*( 9./15 )) ;
	a2->qzzz -= ka3*(zt*zt*zt - zt*( 24./80 )) ;
	a2->qzzz -= kb3*(zt*zt*zt - zt*( 42./(14*18)));
	a1->qzzz += k3*(zt*zt*zt - zt*( 9./15 )) ;
	a1->qzzz += ka3*(zt*zt*zt - zt*( 24./80 )) ;
	a1->qzzz += kb3*(zt*zt*zt - zt*( 42./(14*18)));
#endif
	}else {
	a1->close[inclose++] = (*atomall)[i];
	if( inclose == NCLOSE)
	{
	aaerror(
	" fv_update_nonbon> too many atoms increase NCLOSE or decrease mxcut");
	}
	}
SKIPNEW:  j =  j;
	}
	}
	}
	
	a1->px = a1->dx*lambda + a1->x;
	a1->py = a1->dy*lambda + a1->y;
	a1->pz = a1->dz*lambda + a1->z;
	}
	
	a_inactive_f_zero();
	free( atomlist);
	free( nodelist);
	free( vector);
	free (atomall);
	return 1;
}
/* 当前文件是D:\Read\restrain.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM *atom1,*atom2;
	float length,k;
	void *next;
	}  RESTRAIN;
#define RLONG sizeof(RESTRAIN)
RESTRAIN *restrain_first = NULL;
RESTRAIN *restrain_last = NULL;
int restrain( p1,p2,bl,fk)
	int p1,p2;
	float bl,fk ;
	{
	ATOM *ap1,*ap2,*a_m_serial();
	RESTRAIN *new;
	char line[80];
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	if( (ap1 == NULL) || (ap2 == NULL) )
	{
	sprintf( line,"undefined atom in restrain %d %d \0",p1,p2);
	aaerror( line );
	return 0;
	}
	new = restrain_first;
	if( new != NULL)
	{
	while(1)
	{
		if( new == NULL) break;
		if( (new->atom1 == ap1 && new->atom2 == ap2) ||
(new->atom1 == ap2 && new->atom2 == ap1) )
		{
		new->length = bl; new->k = fk; return 1;
		}
		if( new == new->next) break;
		new = new->next;
	}
	}
	if( ( new = malloc( RLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( restrain_first == NULL) restrain_first = new;
	if( restrain_last == NULL) restrain_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
	new -> length = bl;
	new -> k = fk;
	new -> next = new;
	restrain_last -> next = new;
	restrain_last = new;
	return 1;
	}
int v_restrain( V, lambda )
	float *V,lambda;
{
	RESTRAIN *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = restrain_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r); *V += bp->k*( r - bp->length)*(r - bp->length);
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_restrain(lambda)
float lambda;
{
	RESTRAIN *bp;
	float r,k,ux,uy,uz;
	ATOM *a1,*a2;
	bp = restrain_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1; a2 = bp->atom2;
	if( lambda == 0.)
	{
	ux = (a2->x - a1->x);
	uy = (a2->y - a1->y);
	uz = (a2->z - a1->z);
	}else{
	ux = (a2->x -a1->x +lambda*(a2->dx-a1->dx));
	uy = (a2->y -a1->y +lambda*(a2->dy-a1->dy));
	uz = (a2->z -a1->z +lambda*(a2->dz-a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { r = 0; ux = 1.; uy = 0.; uz = 0.; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	ux = 2*k*(r-bp->length)*ux;
	uy = 2*k*(r-bp->length)*uy;
	uz = 2*k*(r-bp->length)*uz;
	a1->fx += ux;
	a1->fy += uy;
	a1->fz += uz;
	a2->fx -= ux;
	a2->fy -= uy;
	a2->fz -= uz;
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_restrain( a1,restrained,mrestrain,inrestrain)
ATOM *a1, *restrained[];
int mrestrain,*inrestrain ;
{
	RESTRAIN *mine;
	mine = restrain_first;
	*inrestrain = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		restrained[(*inrestrain)++] = mine->atom2;
	}
	if( mine->atom2 == a1)
	{
		restrained[(*inrestrain)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *inrestrain == mrestrain ) return;
	}		
}
void dump_restrains( FILE *where )
{
	RESTRAIN *b;
	ATOM *a1,*a2;
	b = restrain_first;
	if( b == NULL ) return;
	while( (b->next != b) )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"restrain %d %d %f %f ;\n",a1->serial,a2->serial,
		b->length,b->k);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;
	fprintf( where,"restrain %d %d %f %f ;\n",a1->serial,a2->serial,
		b->length,b->k);
}	
int a_restrain( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	RESTRAIN *bp;
	float r,xt,yt,zt;
	ATOM *a1,*a2;
	bp = restrain_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2;
	if(( a1->serial >= ilow && a1->serial <=ihigh)
	 ||( a2->serial >= ilow && a2->serial <=ihigh))
	{
	if( lambda == 0.)
	{
	r = (a1->x - a2->x)*(a1->x - a2->x);
	r = r + (a1->y - a2->y)*(a1->y - a2->y);
	r = r + (a1->z - a2->z)*(a1->z - a2->z);
	} else
	{
	xt = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	yt = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	zt = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	r = sqrt(r); zt= bp->k*( r - bp->length)*(r - bp->length);
	*V += zt;
	fprintf(op,"Restrain %d %d E %f value %f error %f\n"
		,a1->serial,a2->serial,zt,r,r-bp->length);
	}
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
/* 当前文件是D:\Read\significance.c*/

int significance(op)
FILE *op;
{
	int get_i_variable();
	float get_f_variable();
	int ns,na,a_number();
	float delta,rmsd;
	ns = get_i_variable("numstp");
	na = a_number();
	delta = get_f_variable("delta");
	rmsd = get_f_variable("rmsdev");
	if( ns <= 0 )
	{ fprintf(op," you are cheating, seti numstp <number of MD steps>\n");
	}
	
	if( delta > 20. || delta < -20.)
	{
	fprintf( op," The drift in the total energy is too high\n");	
	return 0;
	}
	if( ns < 100 && rmsd > 0.01 )
	{
	fprintf( op," The RMSD is too high \n");
	return 0;
	}
	if( ns < 1000 && ns > 99 && rmsd > 0.1 )
	{
	fprintf( op," The RMSD is too high \n");
	return 0;
	}
	if( ns < 10000 && ns > 999 && rmsd > 1.0 )
	{
	fprintf( op," The RMSD is too high \n");
	return 0;
	}
	fprintf(op," The run is ok\n");
	return 0;
}
/* 当前文件是D:\Read\tailor.c*/

#define ANSI 1
#ifdef ANSI
#endif
void tailor_qab( who, q,a,b)
int who;
float q, a, b;
{
ATOM *ap,*a_m_serial();
ap = a_m_serial( who );
if( ap == NULL ) {aaerror(" undefined atom in tailor_qab"); return;}
ap->q = q; ap->a = a; ap->b = b;
return;
}
void tailor_include( from, to )
int from , to;
{
ATOM *ap1,*ap2,*a_m_serial();
int i;
ap1 = a_m_serial( from );
if( ap1 == NULL ) {aaerror(" undefined atom in tailor_include"); return;}
ap2 = a_m_serial( to );
if( ap2 == NULL ) {aaerror(" undefined atom in tailor_include"); return;}
for( i=0; i< ap1->dontuse; i++)
{ if( ap1->excluded[i] == ap2) break; }
if( i < ap1->dontuse-1 )
{
	for(; i< ap1->dontuse-1; i++)
		{
		ap1->excluded[i] = ap1->excluded[i+1];
		ap1->exkind[i] = ap1->exkind[i+1];
		}
}
ap1->exkind[(ap1->dontuse)] = 0;
ap1->dontuse -= 1;
for( i=0; i< ap2->dontuse; i++)
{ if( ap2->excluded[i] == ap1) break; }
if( i < ap2->dontuse-1 )
{
	for(; i< ap2->dontuse-1; i++)
		{
		ap2->excluded[i] = ap2->excluded[i+1];
		ap2->exkind[i] = ap2->exkind[i+1];
		}
}
ap2->exkind[(ap2->dontuse)] = 0;
ap2->dontuse -= 1;
}
void tailor_exclude( from, to )
int from , to;
{
ATOM *ap1,*ap2,*a_m_serial();
int set_i_variable(),get_i_variable();
int i;
ap1 = a_m_serial( from );
if( ap1 == NULL ) {aaerror(" undefined atom in tailor_exclude"); return;}
ap2 = a_m_serial( to );
if( ap2 == NULL ) {aaerror(" undefined atom in tailor_exclude"); return;}
if( ap1->dontuse == NEXCLUDE)
	{aaerror(" cannot add an atom to the exclude list "); return; }
for( i=0; i< ap1->dontuse; i++)
{  if(ap1->excluded[i] == ap2) goto FOUND; }
ap1->exkind[(ap1->dontuse)] = 1;
ap1->excluded[(ap1->dontuse)++] = ap2;
FOUND:
if( ap2->dontuse == NEXCLUDE)
	{aaerror(" cannot add an atom to the exclude list "); return; }
for( i=0; i< ap2->dontuse; i++)
{  if(ap2->excluded[i] == ap1) return; }
ap2->exkind[(ap2->dontuse)] = 1;
ap2->excluded[(ap2->dontuse)++] = ap1;
i = 0;
i = get_i_variable("numtail");
i = i + 1;
set_i_variable("numtail", i );
}
/* 当前文件是D:\Read\tether.c*/

#define ANSI 1
#ifdef ANSI
#endif
typedef struct{
	ATOM *atom1;
	float k,x,y,z;
	void *next;
	}  TETHER;
#define tetherLONG sizeof(TETHER)
TETHER *tether_first = NULL;
TETHER *tether_last = NULL;
int tether( p1,fk,x,y,z)
	int p1;
	float fk ,x,y,z;
	{
	ATOM *ap1,*a_m_serial();
	TETHER *new;
	char line[80];
	ap1 = a_m_serial( p1 );
	if( (ap1 == NULL)  )
	{
	sprintf( line,"undefined atom in tether %d \0",p1);
	aaerror( line );
	return 0;
	}
	if( tether_first != NULL)
	{
	new = tether_first;
	while(1)
	{
		if( new ->next == NULL) break;
		if( new->atom1 == ap1)
		{
			new -> k = fk;
			new -> x = x;
			new -> y = y;
			new -> z = z;
			return 1;
		}
		if( new->next == new ) break;
		new = new->next;
	}
	}	
	if( ( new = malloc( tetherLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( tether_first == NULL) tether_first = new;
	if( tether_last == NULL) tether_last = new;
	new -> atom1 = ap1;
	new -> k = fk;
	new -> x = x;
	new -> y = y;
	new -> z = z;
	new -> next = new;
	tether_last -> next = new;
	tether_last = new;
	return 1;
	}
int alltether( fk)
float fk ;
{
	ATOM *ap1 ;
	ATOM *a_next();	
	int i,numatm,a_number();
	numatm = a_number();
	if( numatm < 1 ) return 0;
	for( i=0; i< numatm; i++)
	{
		ap1 = a_next(i);
		if( fabs(ap1->x ) > 1.e-8)
		if( fabs(ap1->y ) > 1.e-8)
		if( fabs(ap1->z ) > 1.e-8)
		{
			if( tether( ap1->serial, fk, ap1->x,ap1->y,ap1->z) )
			{ } else {return 0 ;}
		}
	}
	return numatm;
}
int v_tether( V, lambda )
	float *V,lambda;
{
	TETHER *bp;
	float r,xt,yt,zt;
	ATOM *a1;
	bp = tether_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1;
	if( a1->active ){
	if( lambda == 0.)
	{
	r =     (a1->x - bp->x)*(a1->x - bp->x);
	r = r + (a1->y - bp->y)*(a1->y - bp->y);
	r = r + (a1->z - bp->z)*(a1->z - bp->z);
	} else
	{
	xt = (a1->x -bp->x +lambda*(a1->dx));
	yt = (a1->y -bp->y +lambda*(a1->dy));
	zt = (a1->z -bp->z +lambda*(a1->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	 *V += bp->k*r ;
	 }
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_tether(lambda)
float lambda;
{
	TETHER *bp;
	float r,k,ux,uy,uz;
	ATOM *a1;
	bp = tether_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1;
	if( a1->active){
	if( lambda == 0.)
	{
	ux = (a1->x - bp->x );
	uy = (a1->y - bp->y );
	uz = (a1->z - bp->z );
	}else{
	ux = (a1->x -bp->x +lambda*(a1->dx));
	uy = (a1->y -bp->y +lambda*(a1->dy));
	uz = (a1->z -bp->z +lambda*(a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { goto SKIP; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	ux = 2*k*(r)*ux;
	uy = 2*k*(r)*uy;
	uz = 2*k*(r)*uz;
	a1->fx -= ux;
	a1->fy -= uy;
	a1->fz -= uz;
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void dump_tethers( FILE *where )
{
	TETHER *b;
	ATOM *a1;
	b = tether_first;
	if( b == NULL ) return;
	while( (b->next != b) )
	{
	if( b->next == NULL) return;
	a1 = b->atom1;
	fprintf( where,"tether %d %f %f %f %f ;\n",a1->serial,
		b->k,b->x,b->y,b->z);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1;
	fprintf( where,"tether %d %f %f %f %f ;\n",a1->serial,
		b->k,b->x,b->y,b->z);
}	
int a_tether( V, lambda,ilow,ihigh,op )
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	TETHER *bp;
	float r,xt,yt,zt;
	float rms, rmax;
	int tried,imax;
	ATOM *a1;
	float bstrot();
	float (*x)[],(*y)[],(*z)[],(*xx)[],(*yy)[],(*zz)[];
	float matrix[3][3],delta[3];
	int numatm,a_number();
	
	rms = 0.; rmax = -1.;
	tried = 0;
	bp = tether_first;
if( bp == NULL ) return 1;
	numatm = a_number();
	x = malloc( numatm*sizeof(float));
	y = malloc( numatm*sizeof(float));
	z = malloc( numatm*sizeof(float));
	xx = malloc( numatm*sizeof(float));
	yy = malloc( numatm*sizeof(float));
	zz = malloc( numatm*sizeof(float));
	if( x == NULL || y == NULL || z== NULL || xx == NULL ||
		yy == NULL || zz== NULL)
		{aaerror("cannot allocate memory"); return 1;}
	while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1;
	if( a1->serial >= ilow && a1->serial <= ihigh)
	{
	if( lambda == 0.)
	{
	r =     (a1->x - bp->x)*(a1->x - bp->x);
	r = r + (a1->y - bp->y)*(a1->y - bp->y);
	r = r + (a1->z - bp->z)*(a1->z - bp->z);
	} else
	{
	xt = (a1->x -bp->x +lambda*(a1->dx));
	yt = (a1->y -bp->y +lambda*(a1->dy));
	zt = (a1->z -bp->z +lambda*(a1->dz));
	r = xt*xt+yt*yt+zt*zt;
	}
	(*x)[tried] = a1->x+lambda*a1->dx;
	(*y)[tried] = a1->y+lambda*a1->dy;
	(*z)[tried] = a1->z+lambda*a1->dz;
	(*xx)[tried] = bp->x;
	(*yy)[tried] = bp->y;
	(*zz)[tried] = bp->z;
	tried += 1;
	rms = rms + r;
	if( r > rmax ) {rmax = r; imax = a1->serial;}
	zt = bp->k*r ;
	*V += zt;
#ifndef SPEC_CPU2000
	fprintf(op,"Tether %d E %f error %f\n",a1->serial,zt,sqrt(r));
#endif
	}
	if( bp == bp->next ) break;
	bp = bp->next;
}
	   if( tried > 0){
		rms = sqrt(rms/tried); rmax = sqrt(rmax);
	fprintf(op," RMSD %f Maximum Deviation %f \n",rms,rmax);
	 fprintf(op," RMSD after superposition %f\n",
			bstrot( &(*x)[0], &(*y)[0], &(*z)[0], &(*xx)[0], &(*yy)[0],
			&(*zz)[0],tried,matrix,delta) );
	set_f_variable("rmsdev",rms);
	   }
	free(zz); free(yy); free(xx); free(z); free(y); free(x);
return 1;
}
float bstrot( x,y,z,xx,yy,zz, na, matrix,delta)
int na;
float x[],y[],z[];
float xx[],yy[],zz[];
float matrix[3][3], delta[3];
{
	float tensor[3][3],cx,cy,cz,cxx,cyy,czz;
	float tx,ty,tz,txx,tyy,tzz;
	float rms;
	float sx[3][3],sy[3][3],sz[3][3];
	float sq[3][3];
	void cpyvec();
	void matmul();
	int i,j,ipass;
	if( na < 1) return -1.;
	cx = 0.;
	cy = 0.;
	cz = 0.;
	cxx = 0.;
	cyy = 0.;
	czz = 0.;
	for( i=0; i< na; i++)
	{
		cx += x[i];
		cy += y[i];
		cz += z[i];
		cxx += xx[i];
		cyy += yy[i];
		czz += zz[i];
	}
	cx /= na;
	cy /= na;
	cz /= na;
	cxx /= na;
	cyy /= na;
	czz /= na;
	for( i=0; i< 3; i++)
	for( j=0; j< 3; j++)
	{
		tensor[i][j] = 0.;
		matrix[i][j] = 0.;
		sx[i][j] = 0.;
		sy[i][j] = 0.;
		sz[i][j] = 0.;
	}
	matrix[0][0] = 1.;	
	matrix[1][1] = 1.;	
	matrix[2][2] = 1.;	
	sx[0][0] = 1.;
	sy[1][1] = 1.;
	sz[2][2] = 1.;
	for( i=0; i<na; i++)
	{
		tx = x[i] - cx;	
		ty = y[i] - cy;	
		tz = z[i] - cz;	
		txx = xx[i] - cxx;	
		tyy = yy[i] - cyy;	
		tzz = zz[i] - czz;	
		tensor[0][0] += tx*txx;
		tensor[0][1] += tx*tyy;
		tensor[0][2] += tx*tzz;
		tensor[1][0] += ty*txx;
		tensor[1][1] += ty*tyy;
		tensor[1][2] += ty*tzz;
		tensor[2][0] += tz*txx;
		tensor[2][1] += tz*tyy;
		tensor[2][2] += tz*tzz;
	}
	for( ipass = 0; ipass < 20; ipass ++)
	{
	rms = 0.;
	
		tx = atan2( tensor[2][1]-tensor[1][2],
			tensor[1][1]+tensor[2][2]);
		rms += fabs(tx);
		ty = cos(tx); tz = sin(tx);
		sx[1][1] = ty;
		sx[2][1] = -tz;
		sx[1][2] = tz;
		sx[2][2] = ty;
		matmul( sx,tensor,sq,3,3);
		cpyvec(sq,tensor,9);
		matmul( sx,matrix,sq,3,3);
		cpyvec( sq,matrix,9);
	
		tx = atan2( tensor[2][0]-tensor[0][2],
			tensor[0][0]+tensor[2][2]);
		rms += fabs(tx);
		ty = cos(tx); tz = sin(tx);
		sy[0][0] = ty;
		sy[2][0] = -tz;
		sy[0][2] = tz;
		sy[2][2] = ty;
		matmul( sy,tensor,sq,3,3);
		cpyvec(sq,tensor,9);
		matmul( sy,matrix,sq,3,3);
		cpyvec( sq,matrix,9);
	
		tx = atan2( tensor[0][1]-tensor[1][0],
			tensor[1][1]+tensor[0][0]);
		rms += fabs(tx);
		ty = cos(tx); tz = sin(tx);
		sz[1][1] = ty;
		sz[0][1] = -tz;
		sz[1][0] = tz;
		sz[0][0] = ty;
		matmul( sz,tensor,sq,3,3);
		cpyvec(sq,tensor,9);
		matmul( sz,matrix,sq,3,3);
		cpyvec( sq,matrix,9);
		if( rms < 1.e-7) break;
	}
	rms = 0.;
	for(i=0; i< na; i++)
	{
	txx = xx[i] - cxx;
	tyy = yy[i] - cyy;
	tzz = zz[i] - czz;
	tx = matrix[0][0]*txx + matrix[1][0]*tyy + matrix[2][0]*tzz;
	ty = matrix[0][1]*txx + matrix[1][1]*tyy + matrix[2][1]*tzz;
	tz = matrix[0][2]*txx + matrix[1][2]*tyy + matrix[2][2]*tzz;
	tx += cx - x[i];
	ty += cy - y[i];
	tz += cz - z[i];
	rms += tx*tx + ty*ty + tz*tz;
	}
	tx = matrix[0][0]*cxx + matrix[1][0]*cyy + matrix[2][0]*czz;
	ty = matrix[0][1]*cxx + matrix[1][1]*cyy + matrix[2][1]*czz;
	tz = matrix[0][2]*cxx + matrix[1][2]*cyy + matrix[2][2]*czz;
	delta[0] = cx - tx;
	delta[1] = cy - ty;
	delta[2] = cz - tz;
	return sqrt(rms/na);
}
void cpyvec(orig,copy,n)
float orig[],copy[];
int n;
{
	int i;
	for( i=0; i< n; i++)
		copy[i] = orig[i];
}
void matmul( a,b,c,n,m)
float a[],b[],c[];
int n,m;
{
	int i,j,k,ioff,koff;
	for( i=0; i< n*n; i++)
		c[i] = 0.;
	for( i=0; i< n; i++)
	{
		ioff = i*n;
		for( j=0; j< n; j++)
		{
		koff = 0.;
		for( k=0; k<m; k++)
		{
		c[ ioff +j] += a[ioff + k] *b[ j +koff];
		koff += m;
		}
		}
	}
}
int v_ho_tether( V, lambda )
	float *V,lambda;
{
	TETHER *bp;
	float r,xt,yt,zt;
	ATOM *a1;
float hol, get_f_variable();
	hol = get_f_variable( "lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	if( hol == 1.) return 0;
	bp = tether_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1;
	if( a1->active ){
	if( lambda == 0.)
	{
	xt = (a1->x -bp->x );
	yt = (a1->y -bp->y );
	zt = (a1->z -bp->z );
	} else
	{
	xt = (a1->x + lambda*(a1->dx) -bp->x);
	yt = (a1->y + lambda*(a1->dy) -bp->y);
	zt = (a1->z + lambda*(a1->dz) -bp->z);
	}
	r =(xt*xt+yt*yt+zt*zt)*(1.-hol)*(1.-hol);
	 *V += bp->k*r ;
	 }
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_ho_tether(lambda)
float lambda;
{
	TETHER *bp;
	float r,k,ux,uy,uz;
	ATOM *a1;
float hol, get_f_variable();
	hol = get_f_variable( "lambda");
	if( hol < 0. ) hol = 0.;
	if( hol > 1. ) hol = 1.;
	if( hol == 1.) return 0;
	bp = tether_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	k = bp->k;
	a1 = bp->atom1;
	if( a1->active){
	if( lambda == 0.)
	{
	ux = (a1->x - bp->x );
	uy = (a1->y - bp->y );
	uz = (a1->z - bp->z );
	}else{
	ux = (a1->x -bp->x +lambda*(a1->dx));
	uy = (a1->y -bp->y +lambda*(a1->dy));
	uz = (a1->z -bp->z +lambda*(a1->dz));
	}
	r = ux*ux + uy*uy + uz*uz;
	
	 if( r <= 1.e-5)
	 { goto SKIP; }else{
	r = sqrt(r); ux = ux/r; uy = uy/r; uz = uz/r;
	}
	ux = 2*k*(r)*ux*(1.-hol);
	uy = 2*k*(r)*uy*(1.-hol);
	uz = 2*k*(r)*uz*(1.-hol);
	a1->fx -= ux;
	a1->fy -= uy;
	a1->fz -= uz;
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
/* 当前文件是D:\Read\tgroup.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define MAXTGROUP 100
#define MAXTGSTEP 24
typedef struct { ATOM *context,*b1,*b2,*b3 ;
		int which ,ntry, ingroup ;
		float base;
		ATOM *group[MAXTGROUP];
		void *next;
		}  TGROUP ;
TGROUP *tg_first = NULL;
#define tg_long sizeof(TGROUP)
int tgroup( which,context,b1,b2,b3,base,ntry )
int which ,context,b1,b2,b3,ntry ;
float base;
{
TGROUP *tgp,*tgo;
ATOM *bonded[20],*a_m_serial();
ATOM *newest[MAXTGROUP];
ATOM *newer[MAXTGROUP];
int in_newest,in_newer;
int  i,j,k,l,ll;
char line[80];
void get_bond();
	if( ntry == 0 )
	{ base = 0. ; ntry = 6 ;}
	tgp = tg_first;
	tgo = tgp;
	if( which == 0)
	{ aaerror("warning tg_group 0 will never be accessed\n"); return 0;}
	while(tgp != NULL)
	{
	if( tgp->which == which) goto found;
	tgo = tgp;
	tgp = tgp->next;
	}
	if( (tgp = malloc( tg_long)) == NULL)
	{ aaerror(" cannot allocate memory for a tg_group\n"); exit(0);}	
	if( tgo != NULL) tgo->next = tgp;
	if( tgo == NULL) tg_first = tgp;
	tgp->next = NULL;
found:
	if( context < 0 || b1 < 0 || b2 < 0 || b3 < 0)
	{
	if( tgo != NULL ) tgo->next = tgp->next;
	if( tgo == NULL ) tg_first = tgp->next;
	free( tgp );
	return 1;
	}
	tgp->which = which;
	tgp->context = a_m_serial(context);
	tgp->b1 = a_m_serial(b1);
	tgp->b2 = a_m_serial(b2);
	tgp->b3 = a_m_serial(b3);
	if( tgp->context == NULL )
	{
	sprintf(line," tgroup %d  %d atom not defined cannot define tgroup ",which,context);
	aaerror( line);
	return 1;}
	if( tgp->b1 == NULL )
	{
	sprintf(line," tgroup %d  %d atom not defined cannot define tgroup ",which,b1);
	aaerror( line);
	return 1;}
	if( tgp->b2 == NULL )
	{
	sprintf(line," tgroup %d  %d atom not defined cannot define tgroup ",which,b2);
	aaerror( line);
	return 1;}
	if( tgp->b3 == NULL )
	{
	sprintf(line," tgroup %d  %d atom not defined cannot define tgroup ",which,b3);
	aaerror( line);
	return 1;}
	tgp->base = base *3.1415926589793 /180.;
	for( k=0; k< MAXTGROUP; k++)
		tgp->group[k] = NULL;
	if( ntry > MAXTGSTEP) ntry = MAXTGSTEP;
	tgp->ntry = ntry;
	get_bond( tgp->b2, bonded,20,&j);
	for( k=0; k< j; k++)
	{
	if( bonded[k] != tgp->context
	   && bonded[k] != tgp->b3
	   && bonded[k] != tgp->b1 ) break;
	}
	newest[0] = tgp->b3;
	tgp->group[0] = tgp->b3;
	tgp->ingroup = 1;
	in_newest = 1;
	if( k != j ){
	newest[1] = bonded[k];
	tgp->group[1] = bonded[k];
	tgp->ingroup = 2;
	in_newest = 2;
	for( i = 0; i < j; i++)
	{
		l = 1;
		for( k=0; k< in_newest; k++)
		{ if(newest[k] == bonded[i]) { l = 0; break;} }
		if( bonded[i] == tgp->context) l = 0;
		if( bonded[i] == tgp->b1) l = 0;
		if( bonded[i] == tgp->b2) l = 0;
		if( bonded[i] == tgp->b3) l = 0;
		if( l == 1) {	
		tgp->group[tgp->ingroup++ ] = bonded[i];
		newest[in_newest++] = bonded[i];
			}
	}
	}
	while( in_newest > 0 )
	{
	in_newer = 0;
	for( l=0; l < in_newest; l++)
	{
	get_bond( newest[l],bonded,20,&j);
	for( i =0; i< j; i++)
	{
		ll = 1;
		for( k=0; k< tgp->ingroup ; k++)
		{ if( tgp->group[k] == bonded[i])
			{ ll = 0; break; }
		}
		if( bonded[i] == tgp->context) ll = 0;
		if( bonded[i] == tgp->b1) ll = 0;
		if( bonded[i] == tgp->b2) ll = 0;
		if( bonded[i] == tgp->b3) ll = 0;
		if( ll == 1 )
		{
		tgp->group[ tgp->ingroup++ ] = bonded[i];
		newer[in_newer++] = bonded[i];
		if( tgp->ingroup > MAXTGROUP )
		{aaerror(" too many atoms in a tgroup - must exit\n"); exit(0);}
		}	
	}
	}
	for( i= 0; i< in_newer; i++)
	{ newest[i] = newer[i]; }
	in_newest = in_newer;
	}
	if( tgp->ingroup > MAXTGROUP )
		{aaerror(" too many atoms in a tgroup - must exit\n"); exit(0);}
	return 1;
}
tsearch( t1 ,t2 ,t3,t4,t5,t6,t7,t8 )
int t1,t2,t3,t4,t5,t6,t7,t8;
{
	TGROUP  *grouplist[8],*match_tgroup();
	int ngroup,i,j;
	int bestlist[8];
	float V;
	void tg_do_search();
	void tg_gen_con(), tg_init(),tg_apply();
	ngroup = 8;
	for( i=0; i< ngroup ; i++)
		grouplist[i] = NULL;
	if( t8 <= 0 ) ngroup = 7;
	if( t7 <= 0 ) ngroup = 6;
	if( t6 <= 0 ) ngroup = 5;
	if( t5 <= 0 ) ngroup = 4;
	if( t4 <= 0 ) ngroup = 3;
	if( t3 <= 0 ) ngroup = 2;
	if( t2 <= 0 ) ngroup = 1;
	if( t1 <= 0 ) ngroup = 0;
	if( ngroup == 0 ) return 1;
	grouplist[7] = match_tgroup( t8 );
	grouplist[6] = match_tgroup( t7 );
	grouplist[5] = match_tgroup( t6 );
	grouplist[4] = match_tgroup( t5 );
	grouplist[3] = match_tgroup( t4 );
	grouplist[2] = match_tgroup( t3 );
	grouplist[1] = match_tgroup( t2 );
	grouplist[0] = match_tgroup( t1 );
	for( i=0; i< ngroup; i++)
	{
	if( grouplist[i] != NULL)
	{ for( j=0; j< grouplist[i]->ingroup; j++)
	  if( !(grouplist[i]->group[j]->active) )
		{grouplist[i] = NULL; break;}
	  if( grouplist[i] != NULL )
		if(!(grouplist[i]->b3->active) )
		{grouplist[i] = NULL; }
	}
	}
	for( i = 0; i< ngroup; i++)
	{
	if( grouplist[i] == NULL)
	{
		for( j=i; j< ngroup-1; j++)
		{ grouplist[j] = grouplist[j+1]; }
		ngroup -= 1;
	}
	}
	tg_init( grouplist,&ngroup,0 );
	tg_do_search(&V, grouplist,bestlist,0,ngroup );
	tg_gen_con( grouplist,bestlist,ngroup );
}
void tg_gen_con( gl,bl,ngl)
TGROUP *gl[];
int bl[], ngl;
{
ATOM *a1;
int i,j;
void tg_apply();
for( i=0 ; i < ngl ; i++)
{
	j = ngl -i -1;
	tg_apply( gl[j],bl[j]) ;
}
	for( i=ngl-1; i> -1 ; i -- )
	{
	for( j=0; j< gl[i]->ingroup ; j++)
	{
	a1 = gl[i]->group[j];
	a1->x = a1->dx;
	a1->y = a1->dy;
	a1->z = a1->dz;
	}
	}
}	
void tg_init( gl,ng ,deep)
TGROUP *gl[];
int *ng,deep;
{
ATOM *a1,*a2,*a3,*a4;
float x1,y1,z1,x2,y2,z2,x3,y3,z3;
float cx1,cy1,cz1,cx2,cy2,cz2;
float dp,r;
int i ,j;
int ngl;
void tg_d_apply();
ATOM *a_next();
int  a_number();
	if( deep == 0 )
	{
	j = a_number();
	for( i=0; i< j; i++)
	{
	a1 = a_next(i);
	a1->dx = a1->x;
	a1->dy = a1->y;
	a1->dz = a1->z;
	}
	}
	ngl = *ng;
	for( i=ngl-1; i> -1 ; i -- )
	{
	if( gl[i] == NULL) {if( i == 0) {*ng = 0; return;}
			 *ng = i; tg_init( gl,ng,deep+1); return ;}
	for( j=0; j< gl[i]->ingroup ; j++)
	{
	a1 = gl[i]->group[j];
	if( a1 == NULL) return;
	a1->dx = a1->x;
	a1->dy = a1->y;
	a1->dz = a1->z;
	}
	a1 = gl[i]->context;
	a2 = gl[i]->b1;
	a3 = gl[i]->b2;
	a4 = gl[i]->b3;
	a1->dx = a1->x;
	a1->dy = a1->y;
	a1->dz = a1->z;
	a2->dx = a2->x;
	a2->dy = a2->y;
	a2->dz = a2->z;
	a3->dx = a3->x;
	a3->dy = a3->y;
	a3->dz = a3->z;
	a4->dx = a4->x;
	a4->dy = a4->y;
	a4->dz = a4->z;
x1 = (a1->x -a2->x );
y1 = (a1->y -a2->y );
z1 = (a1->z -a2->z );
x2 = (a3->x -a2->x );
y2 = (a3->y -a2->y );
z2 = (a3->z -a2->z );
x3 = (a4->x -a3->x );
y3 = (a4->y -a3->y );
z3 = (a4->z -a3->z );
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
if( r < 1.e-4) goto SKIP;
r = sqrt(r);
cx1 = cx1/r;
cy1 = cy1/r;
cz1 = cz1/r;
cx2 = y3*z2 - y2*z3;
cy2 = -x3*z2 + x2*z3;
cz2 = x3*y2 - x2*y3;
r = cx2*cx2 + cy2*cy2 + cz2*cz2;
if( r < 1.e-4) goto SKIP;
r = sqrt(r);
cx2 = cx2/r;
cy2 = cy2/r;
cz2 = cz2/r;
dp = cx1*cx2 + cy1*cy2 + cz1*cz2;
if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
dp = acos(dp);
r = cx1*x3 + cy1*y3 + cz1*z3;
if( r > 0 ) dp =  -dp ;
	r =  gl[i]->base - dp ;
	tg_d_apply( gl[i], r );
	for( j=0; j< gl[i]->ingroup ; j++)
	{
	a1 = gl[i]->group[j];
	a1->x = a1->dx;
	a1->y = a1->dy;
	a1->z = a1->dz;
	}
SKIP:   i = i;
	}
	
}
void tg_do_search( Vp, gl,bl,igl, ngl )
float *Vp;
int igl,ngl,bl[];
TGROUP *gl[];
{
	float vl[MAXTGSTEP],vb;
	int i,ibest;
	int bestlist[MAXTGSTEP][8];
	int lbl[8];
	void tg_apply();
if( igl == 8 ) return;
if( gl[igl] == NULL ) return;
if( igl > ngl) return;
	
	for( i=0; i < gl[igl]->ntry ; i++)
	{
	tg_do_search(&vl[i], gl,lbl,igl+1,ngl );
	tg_nonbon( &vl[i], gl[igl]);
	for( ibest=0; ibest<8; ibest++)
	bestlist[i][ibest] = lbl[ibest];
	if( gl[igl]->ntry > 1)
	{
	tg_apply( gl[igl],1);
	}
	}
	vb = 10e20;
	ibest = 0;
	for( i=0; i< gl[igl]->ntry; i++)
	{
	if( vl[i] < vb ) { vb = vl[i]; ibest = i ;}
	}
	bestlist[ibest][igl] = ibest;
	for( i=0; i<8; i++)
	{ bl[i] = bestlist[ibest][i]; }
	*Vp = vl[ibest];
}
void tg_apply( tgp, num )
TGROUP *tgp;
int num;
{
float nx,ny,nz;
float phi,cphi,sphi;
float rx,ry,rz, nnrx,nnry,nnrz, rnx,rny,rnz;
ATOM *b1,*b2;
int i;
	b1 = tgp->b1;
	b2 = tgp->b2;
	nx = b2->dx - b1->dx;
	ny = b2->dy - b1->dy;
	nz = b2->dz - b1->dz;
	rx = sqrt(nx*nx + ny*ny + nz*nz);
	if( rx < 1.e-6)
	{aaerror(" bad torsion radius in tg_apply \n"); return ;}
	nx = nx/rx;
	ny = ny/rx;
	nz = nz/rx;
	phi = 2.*3.141592653589793 /(float)tgp->ntry * (float)num;
	cphi = cos(phi); sphi = sin(phi);
	for( i=0; i< tgp->ingroup; i++)
	{
		rx = (tgp->group[i])->dx - b1->dx;
		ry = (tgp->group[i])->dy - b1->dy;
		rz = (tgp->group[i])->dz - b1->dz;
		phi = nx*rx + ny*ry + nz*rz;
		nnrx = phi*nx;
		nnry = phi*ny;
		nnrz = phi*nz;
		rnx = ny*rz - nz*ry;
		rny = -nx*rz + nz*rx;
		rnz = nx*ry - ny*rx;
		phi = (1.-cphi);
		rx = cphi*rx + phi*nnrx + sphi*rnx;
		ry = cphi*ry + phi*nnry + sphi*rny;
		rz = cphi*rz + phi*nnrz + sphi*rnz;
		(tgp->group[i])->dx = rx + b1->dx;
		(tgp->group[i])->dy = ry + b1->dy;
		(tgp->group[i])->dz = rz + b1->dz;
	}
}
void tg_d_apply( tgp, off )
TGROUP *tgp;
float off;
{
float nx,ny,nz;
float phi,cphi,sphi;
float rx,ry,rz, nnrx,nnry,nnrz, rnx,rny,rnz;
ATOM *b1,*b2;
int i;
	b1 = tgp->b1;
	b2 = tgp->b2;
	nx = b2->dx - b1->dx;
	ny = b2->dy - b1->dy;
	nz = b2->dz - b1->dz;
	rx = sqrt(nx*nx + ny*ny + nz*nz);
	if( rx < 1.e-6)
	{aaerror(" bad torsion radius in tg_apply \n"); return ;}
	nx = nx/rx;
	ny = ny/rx;
	nz = nz/rx;
	phi = off;
	cphi = cos(phi); sphi = sin(phi);
	for( i=0; i< tgp->ingroup; i++)
	{
		rx = (tgp->group[i])->dx - b1->dx;
		ry = (tgp->group[i])->dy - b1->dy;
		rz = (tgp->group[i])->dz - b1->dz;
		phi = nx*rx + ny*ry + nz*rz;
		nnrx = phi*nx;
		nnry = phi*ny;
		nnrz = phi*nz;
		rnx = ny*rz - nz*ry;
		rny = -nx*rz + nz*rx;
		rnz = nx*ry - ny*rx;
		phi = (1.-cphi);
		rx = cphi*rx + phi*nnrx + sphi*rnx;
		ry = cphi*ry + phi*nnry + sphi*rny;
		rz = cphi*rz + phi*nnrz + sphi*rnz;
		(tgp->group[i])->dx = rx + b1->dx;
		(tgp->group[i])->dy = ry + b1->dy;
		(tgp->group[i])->dz = rz + b1->dz;
	}
}
void dump_tgroup( FILE *where )
{
TGROUP *tgp;
	tgp = tg_first;
	while (tgp != NULL)
	{
	fprintf( where," tgroup %d %d %d %d %d %f %d ;\n",
	tgp->which, tgp->context->serial,
	tgp->b1->serial,
	tgp->b2->serial,
	tgp->b3->serial,
	tgp->base*180./3.141592653589793, tgp->ntry);
	tgp = tgp->next;
	}
}
TGROUP *match_tgroup( i )
int i;
{
	TGROUP *tgp ;
	tgp = tg_first;
	while( tgp != NULL )
	{
	if( tgp ->which == i )
	{
		if( tgp->context == NULL) return NULL;
		if( tgp->b1 == NULL) return NULL;
		if( tgp->b2 == NULL) return NULL;
		if( tgp->b3 == NULL) return NULL;
		return tgp;
	}
	tgp = tgp->next;
	}
	return NULL;
}
int tg_nonbon( V ,tgp )
	float *V;
	TGROUP *tgp ;
{
	float r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	int inbond,inangle,i,ii;
	ATOM *a1,*a2;
	ATOM *a_next( );
	float dielectric,ve,va,vh;
	ATOM *a_m_serial();
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	cutoff = get_f_variable("cutoff");
	if( cutoff < 1.) cutoff = 1.e10;
	lcutoff = -cutoff;
	*V = 0.;
	if( tgp == NULL ) return 1;
	for( ii=0; ii<= tgp->ingroup; ii++)
	{
	a1 = tgp->group[ii];
	if( a1 == NULL ) goto NOTANATOM;
	ve = 0.; va = 0.; vh = 0.;
	a2 = a_next(-1);
	while(  (a2 != NULL) && (a2->next != NULL) && a2->next != a2)
	{
	if( a2 == a1) goto SKIP;
	for(i = 0; i< a1->dontuse; i++)
		if( a2 == a1->excluded[i]) goto SKIP;
	xt = (a1->dx - a2->dx);
	if( (xt > cutoff) || (xt < lcutoff) ) goto SKIP;
	yt =  (a1->dy - a2->dy);
	if( (yt > cutoff) || (yt < lcutoff) ) goto SKIP;
	zt =  (a1->dz - a2->dz);
	if( (zt > cutoff) || (zt < lcutoff) ) goto SKIP;
	r = xt*xt+yt*yt+zt*zt;
	if( r < 1.) r = 1.;
	r0 = sqrt(r); r = r*r*r ;
	ve += dielectric*a1->q*a2->q/r0;
	va -= a1->a*a2->a/r;
	vh += a1->b*a2->b/r/r;
SKIP:
	if( a2->next == a2) break;
	a2 = a2->next;
	}
	*V += ve + va + vh;
NOTANATOM:
	i = i;
	}
	return 1;
}
/* 当前文件是D:\Read\torsion.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define TOO_SMALL 1.e-8
#define doublefloat double
typedef struct{
	ATOM *atom1,*atom2,*atom3,*atom4;
	float k,offset;
	int   n;
	void *next;
	}  TORSION;
#define TLONG sizeof(TORSION)
TORSION *torsion_first = NULL;
TORSION *torsion_last = NULL;
int torsion( p1,p2,p3,p4,fk,n,off)
	int p1,p2,p3,p4,n;
	float fk,off;
	{
	TORSION *new;
	ATOM *ap1,*ap2,*ap3,*ap4,*a_m_serial();
	char line[80];
	if(  p1 == p2 || p1 == p3 || p1 == p4
	|| p2 == p3 || p2 == p4 || p3 == p4)
	{
	sprintf( line," same atom in torsion %d %d %d %d \0",p1,p2,p3,p4);
	aaerror( line );
	return 1;
	}
	if( fk == 0.) return 1;
	ap1 = a_m_serial( p1 );
	ap2 = a_m_serial( p2 );
	ap3 = a_m_serial( p3 );
	ap4 = a_m_serial( p4 );
	if( (ap1 == NULL) || (ap2 == NULL) || (ap3==NULL) || (ap4==NULL) )
	{
	sprintf( line,"undefined atom in torsion %d %d %d %d \0",p1,p2,p3,p4);
	aaerror( line );
	return 0;
	}
	if( ( new = malloc( TLONG ) ) == NULL)
	{
	return 0;
	}
	
	if( torsion_first == NULL) torsion_first = new;
	if( torsion_last == NULL) torsion_last = new;
	new -> atom1 = ap1;
	new -> atom2 = ap2;
	new -> atom3 = ap3;
	new -> atom4 = ap4;
	new -> offset = off;
	new -> k = fk;
	new -> n = n;
	new -> next = new;
	torsion_last -> next = new;
	torsion_last = new;
	return 1;
	}
int v_torsion( V, lambda )
	float *V,lambda;
{
	TORSION *bp;
	doublefloat x1,y1,z1,x2,y2,z2,x3,y3,z3;
	doublefloat r,cx1,cy1,cz1,cx2,cy2,cz2;
	doublefloat dp;
	ATOM *a1,*a2,*a3,*a4;
	bp = torsion_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active|| a2->active || a3->active || a4->active) {
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	x3 = (a4->x -a3->x +lambda*(a4->dx-a3->dx));
	y3 = (a4->y -a3->y +lambda*(a4->dy-a3->dy));
	z3 = (a4->z -a3->z +lambda*(a4->dz-a3->dz));
	cx1 = y1*z2 - y2*z1;
	cy1 = -x1*z2 + x2*z1;
	cz1 = x1*y2 - x2*y1;
	r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < TOO_SMALL) goto SKIP;
	r = one/sqrt(r);
	cx1 = cx1*r;
	cy1 = cy1*r;
	cz1 = cz1*r;
	cx2 = y3*z2 - y2*z3;
	cy2 = -x3*z2 + x2*z3;
	cz2 = x3*y2 - x2*y3;
	r = cx2*cx2 + cy2*cy2 + cz2*cz2;
	if( r < TOO_SMALL) goto SKIP;
	r = one/sqrt(r);
	cx2 = cx2*r;
	cy2 = cy2*r;
	cz2 = cz2*r;
	dp = cx1*cx2 + cy1*cy2 + cz1*cz2;
	if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	r = cx1*x3 + cy1*y3 + cz1*z3;
	if( r > 0 ) dp =  -dp ;
	*V += .5*(bp->k)*( 1. + cos( bp->n * dp - bp->offset   )) ;
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
int f_torsion(lambda)
float lambda;
{
	TORSION *bp;
	doublefloat x1,y1,z1,x2,y2,z2,x3,y3,z3;
	doublefloat r,cx1,cy1,cz1,cx2,cy2,cz2;
	doublefloat dp,sdp;
	doublefloat r1,r2,r3,c1,c2,s1,s2;
	doublefloat ux,uy,uz;
	int i;	
	ATOM *a1,*a2,*a3,*a4;
	bp = torsion_first;
if( bp == NULL ) return 1;
i = 0;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( a1->active|| a2->active || a3->active || a4->active) {
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	x3 = (a4->x -a3->x +lambda*(a4->dx-a3->dx));
	y3 = (a4->y -a3->y +lambda*(a4->dy-a3->dy));
	z3 = (a4->z -a3->z +lambda*(a4->dz-a3->dz));
	r1 = sqrt( x1*x1 + y1*y1 + z1*z1);
	r2 = sqrt( x2*x2 + y2*y2 + z2*z2);
	r3 = sqrt( x3*x3 + y3*y3 + z3*z3);
	c1 = (x1*x2 + y1*y2 + z1*z2)/r1/r2;
	c2 = -(x2*x3 + y2*y3 + z2*z3)/r2/r3;
	
	s1 = ( 1. - c1*c1); s2 = ( 1. -c2*c2);
	if( s1 < TOO_SMALL) goto SKIP;
	if( s2 < TOO_SMALL) goto SKIP;
	cx1 = y1*z2 - y2*z1;
	cy1 = -x1*z2 + x2*z1;
	cz1 = x1*y2 - x2*y1;
	r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < TOO_SMALL) goto SKIP;
	r = one/sqrt(r);
	cx1 = cx1*r;
	cy1 = cy1*r;
	cz1 = cz1*r;
	cx2 = y3*z2 - y2*z3;
	cy2 = -x3*z2 + x2*z3;
	cz2 = x3*y2 - x2*y3;
	r = cx2*cx2 + cy2*cy2 + cz2*cz2;
	if( r < TOO_SMALL) goto SKIP;
	r = one/sqrt(r);
	cx2 = cx2*r;
	cy2 = cy2*r;
	cz2 = cz2*r;
	dp = cx1*cx2 + cy1*cy2 + cz1*cz2;
	if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	r = sqrt(x3*x3 +y3*y3 +z3*z3)*
	    sqrt(x2*x2+y2*y2+z2*z2);
	sdp = x3*x2 + y3*y2 + z3*z2;
	sdp = sdp/r;
	ux = x3 - sdp*x2;
	uy = y3 - sdp*y2;
	uz = z3 - sdp*z2;
	r = cx1*ux + cy1*uy + cz1*uz;
	if( r >= 0 ) dp = -dp  ;
	r = -.5*bp->k*bp->n*sin( bp->n*dp - bp->offset);
	
	s1 = one/s1;
	s2 = one/s2;
	if( a1->active){
	a1->fx -= r*cx1/r1*s1;
	a1->fy -= r*cy1/r1*s1;
	a1->fz -= r*cz1/r1*s1;
	}
	if( a2->active){
	a2->fx += r*cx1*(r2-c1*r1)/r2/r1*s1;
	a2->fy += r*cy1*(r2-c1*r1)/r2/r1*s1;
	a2->fz += r*cz1*(r2-c1*r1)/r2/r1*s1;
	a2->fx -= r*cx2*c2/r2*s2;
	a2->fy -= r*cy2*c2/r2*s2;
	a2->fz -= r*cz2*c2/r2*s2;
	}
	if( a3->active){
	a3->fx -= r*cx2*(r2-c2*r3)/r2/r3*s2;
	a3->fy -= r*cy2*(r2-c2*r3)/r2/r3*s2;
	a3->fz -= r*cz2*(r2-c2*r3)/r2/r3*s2;
	a3->fx += r*cx1*c1/r2*s1;
	a3->fy += r*cy1*c1/r2*s1;
	a3->fz += r*cz1*c1/r2*s1;
	}
	if( a4->active){
	a4->fx += r*cx2/r3*s2;
	a4->fy += r*cy2/r3*s2;
	a4->fz += r*cz2/r3*s2;
	}
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
void get_torsion( a1,bonded,mbond,inbond)
ATOM *a1, *bonded[];
int mbond,*inbond ;
{
	TORSION *mine;
	mine = torsion_first;
	*inbond = 0;
	while(1)
	{
	if( (mine == NULL) )
	{
		return;
	}
	if( mine->atom1 == a1)
	{
		bonded[(*inbond)++] = mine->atom4;
	}
	if( mine->atom4 == a1)
	{
		bonded[(*inbond)++] = mine->atom1;
	}
	if( mine == mine->next) return;
	mine = mine->next;
	if( *inbond == mbond ) return;
	}		
}
void dump_torsions( FILE *where )
{
	TORSION *b;
	ATOM *a1,*a2,*a3,*a4;
	float rtodeg;
	b = torsion_first;
	if( b == NULL ) return;
	rtodeg = 180./acos(-1.);
	while( (b->next != b)  )
	{
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3; a4 = b->atom4;
	fprintf( where,"torsion %d %d %d %d %f %d %f ;\n",
		a1->serial,a2->serial,
		a3-> serial,a4->serial,b->k,b->n,b->offset*rtodeg);
	b = b->next;
	}
	if( b->next == NULL) return;
	a1 = b->atom1; a2 = b->atom2;a3 = b->atom3; a4 = b->atom4;
	fprintf( where,"torsion %d %d %d %d %f %d %f ;\n",
		a1->serial,a2->serial,
		a3-> serial,a4->serial,b->k,b->n,b->offset*rtodeg);
}	
int a_torsion( V, lambda ,ilow,ihigh,op)
	float *V,lambda;
	int ilow,ihigh;
	FILE *op;
{
	TORSION *bp;
	float x1,y1,z1,x2,y2,z2,x3,y3,z3;
	float r,cx1,cy1,cz1,cx2,cy2,cz2;
	float dp;
	ATOM *a1,*a2,*a3,*a4;
	bp = torsion_first;
if( bp == NULL ) return 1;
while(1)
{
	if( bp == NULL) return 0;
	a1 = bp->atom1; a2 = bp->atom2; a3 = bp->atom3;
	a4 = bp->atom4;
	if( (a1->serial >= ilow && a1->serial <= ihigh)
	||  (a2->serial >= ilow && a2->serial <= ihigh)
	||  (a3->serial >= ilow && a3->serial <= ihigh)
	||  (a4->serial >= ilow && a4->serial <= ihigh) )
	{
	x1 = (a1->x -a2->x +lambda*(a1->dx-a2->dx));
	y1 = (a1->y -a2->y +lambda*(a1->dy-a2->dy));
	z1 = (a1->z -a2->z +lambda*(a1->dz-a2->dz));
	x2 = (a3->x -a2->x +lambda*(a3->dx-a2->dx));
	y2 = (a3->y -a2->y +lambda*(a3->dy-a2->dy));
	z2 = (a3->z -a2->z +lambda*(a3->dz-a2->dz));
	x3 = (a4->x -a3->x +lambda*(a4->dx-a3->dx));
	y3 = (a4->y -a3->y +lambda*(a4->dy-a3->dy));
	z3 = (a4->z -a3->z +lambda*(a4->dz-a3->dz));
	cx1 = y1*z2 - y2*z1;
	cy1 = -x1*z2 + x2*z1;
	cz1 = x1*y2 - x2*y1;
	r = cx1*cx1 + cy1*cy1 + cz1*cz1;
	if( r < TOO_SMALL) goto SKIP;
	r = sqrt(r);
	cx1 = cx1/r;
	cy1 = cy1/r;
	cz1 = cz1/r;
	cx2 = y3*z2 - y2*z3;
	cy2 = -x3*z2 + x2*z3;
	cz2 = x3*y2 - x2*y3;
	r = cx2*cx2 + cy2*cy2 + cz2*cz2;
	if( r < TOO_SMALL) goto SKIP;
	r = sqrt(r);
	cx2 = cx2/r;
	cy2 = cy2/r;
	cz2 = cz2/r;
	dp = cx1*cx2 + cy1*cy2 + cz1*cz2;
	if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
	dp = acos(dp);
	r = cx1*x3 + cy1*y3 + cz1*z3;
	if( r > 0 ) dp =  -dp ;
	z2 = .5*(bp->k)*( 1. + cos( bp->n * dp - bp->offset   )) ;
	*V += z2;
	fprintf(op,"Torsion %s %d %s %d %s %d %s %d E %f Angle %f error %f\n"
		,a1->name,a1->serial,a2->name,a2->serial,a3->name,a3->serial,
		a4->name,a4->serial, z2,dp*180./3.14159265
	,acos(-(cos(bp->n*dp-bp->offset)))*180./3.14159265 );
	}
SKIP:
	if( bp == bp->next ) return 1;
	bp = bp->next;
}
}
gsdg_torsion( ap )
ATOM *ap;
{
TORSION *tp;
float bond_length();
float b1,b2,b3;
	tp =torsion_first;
	while( 1)
	{
		if( tp == NULL ) return 0;
		if( tp->atom1 == ap)
		{
			b1 = bond_length(ap,tp->atom2);
			b2 = bond_length(tp->atom2,tp->atom3);
			b3 = bond_length(tp->atom3,tp->atom4);
			ap->vx = b2 + .75*(b1+b3);
			ap->vx *= ap->vx;
			ap->vy = 10.;
		}
		if( tp->atom4 == ap)
		{
			b1 = bond_length(ap,tp->atom3);
			b2 = bond_length(tp->atom2,tp->atom3);
			b3 = bond_length(tp->atom2,tp->atom1);
			ap->vx = b2 + .75*(b1+b3);
			ap->vx *= ap->vx;
			ap->vy = 10.;
		}
		if( tp == tp->next) return 0;
		tp = tp->next;
	}
}
/* 当前文件是D:\Read\tset.c*/

#define ANSI 1
#ifdef ANSI
#endif
int set_torsion ( ATOM *, ATOM *, ATOM *, ATOM *, float );
int tset_bond_build( ATOM *, ATOM *, ATOM *, ATOM *);
#ifdef NEWCCALL
int tset( FILE *op, int echo ,int i1,int i2,int i3,int i4, float alpha )
#else
int tset(op,echo, i1,i2,i3,i4, alpha )
int i1,i2,i3,i4;
float alpha ;
FILE *op;
int echo;
#endif
{
	 ATOM *ap,*ap1,*ap2,*ap3,*ap4, *a_m_serial(),*a_next();
	float get_torsion_value();
	float original,delta;
	int numatom,a_number();
	numatom = a_number();
	if( numatom <= 0) return 1;
	ap1 = a_m_serial(i1);
	if( ap1 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap2 = a_m_serial(i2);
	if( ap2 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap3 = a_m_serial(i3);
	if( ap3 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap4 = a_m_serial(i4);
	if( ap4 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	original = get_torsion_value( ap1,ap2,ap3,ap4);
	if( fabs(original  -alpha) < 1.e-3 ) return 1;
	tset_bond_build( ap1,ap2,ap3,ap4);
	delta = alpha -original;
	set_torsion( ap1,ap2,ap3,ap4,delta );
	if( echo )
	fprintf(op,"tset> original  %f delta %f final %f\n", original*180/3.14159,delta*180/3.14159,
			get_torsion_value( ap1,ap2,ap3,ap4)*180/3.14159);
	return 0;
}
#ifdef NEWCCALL
int tmin( FILE *op, int echo ,int i1,int i2,int i3,int i4,int nstep, int (*vfs[])(),int nfs )
#else
int tmin(op,echo, i1,i2,i3,i4,nstep, vfs,nfs )
int i1,i2,i3,i4,nstep;
int (*vfs[])();
FILE *op;
int echo,nfs;
#endif
{
	 ATOM *ap,*ap1,*ap2,*ap3,*ap4, *a_m_serial(),*a_next();
	float get_torsion_value();
	float original,delta;
	float vtemp,vmax;
	int numatom,a_number();
	int i,imax,ifs;
	numatom = a_number();
	if( numatom <= 0) return 1;
	ap1 = a_m_serial(i1);
	if( ap1 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap2 = a_m_serial(i2);
	if( ap2 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap3 = a_m_serial(i3);
	if( ap3 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	ap4 = a_m_serial(i4);
	if( ap4 == NULL){
		aaerror("An atom in tset is not defined");
		 return 1;}
	if( nstep <= 0 ) nstep = 12;
	original = get_torsion_value( ap1,ap2,ap3,ap4);
	tset_bond_build( ap1,ap2,ap3,ap4);
	delta =  -original;
	set_torsion( ap1,ap2,ap3,ap4,delta );
	imax = -1;
	vmax = 10e20;
delta = 2*3.141592653589793 /(float)nstep;
	for( i=0; i< nstep; i++)
	{
		vtemp = 0.;
		for( ifs = 0; ifs < nfs; ifs++)
			 (*vfs[ifs])( &vtemp,0.);
		if( vtemp < vmax)
			{vmax = vtemp; imax = i;}	
	set_torsion( ap1,ap2,ap3,ap4,delta );
	}
	set_torsion( ap1,ap2,ap3,ap4,imax*delta );
	if( echo )
	fprintf(op,"tset> original  %f  final %f\n", original*180/3.14159,
			get_torsion_value( ap1,ap2,ap3,ap4)*180/3.14159);
	return 0;
}
int tset_bond_build( ATOM *ap1, ATOM *ap2, ATOM *ap3, ATOM *ap4)
{
	ATOM *ap,*a_next(),*bonded[20];
	int i , numatom, a_number(),inbond;
	int j,tobonded;
	void get_bond();
	numatom = a_number();
	for( i=0; i< numatom; i++)
	{  ap = a_next(i);
	ap->gx = -1.;
	}	
	tobonded = 0;
	get_bond( ap3,bonded,20,&inbond);
	for( i=0; i< inbond; i++)
	{
		if( bonded[i] != ap1 && bonded[i]!= ap2)
		{ bonded[i]->gx = 0.; tobonded++ ;}
	}
	get_bond( ap4,bonded,20,&inbond);
	for( i=0; i< inbond; i++)
	{
		if( bonded[i] != ap1 && bonded[i]!= ap2)
		{ bonded[i]->gx = 0.; tobonded++ ;}
	}
	ap3->gx = 1.;
	ap4->gx = 1.;	
	while( tobonded > 0 )
	{
		tobonded = 0;
		for( i=0; i< numatom;i++)
		{
		ap = a_next(i);
		if( ap != ap1 && ap != ap2) {
		if( ap->gx == 0.)
		{
		ap->gx = 1.;
		get_bond( ap,bonded,20,&inbond);
			for( j=0; j< inbond; j++)
			{
				if( bonded[j]->gx < 1.)
				{ bonded[j]->gx = 0.; tobonded++ ;}
			}
		}
			}
		}
	}
return 1;
}
float get_torsion_value( a1,a2,a3,a4)
ATOM *a1,*a2,*a3,*a4;
{
float x1,x2,x3,y1,y2,y3,z1,z2,z3;
float cx1,cy1,cz1,cx2,cy2,cz2;
float dp,r;
	
x1 = (a1->x -a2->x );
y1 = (a1->y -a2->y );
z1 = (a1->z -a2->z );
x2 = (a3->x -a2->x );
y2 = (a3->y -a2->y );
z2 = (a3->z -a2->z );
x3 = (a4->x -a3->x );
y3 = (a4->y -a3->y );
z3 = (a4->z -a3->z );
cx1 = y1*z2 - y2*z1;
cy1 = -x1*z2 + x2*z1;
cz1 = x1*y2 - x2*y1;
r = cx1*cx1 + cy1*cy1 + cz1*cz1;
if( r < 1.e-4) goto SKIP;
r = 1./sqrt(r);
cx1 = cx1*r;
cy1 = cy1*r;
cz1 = cz1*r;
cx2 = y3*z2 - y2*z3;
cy2 = -x3*z2 + x2*z3;
cz2 = x3*y2 - x2*y3;
r = cx2*cx2 + cy2*cy2 + cz2*cz2;
if( r < 1.e-4) goto SKIP;
r = 1./sqrt(r);
cx2 = cx2*r;
cy2 = cy2*r;
cz2 = cz2*r;
dp = cx1*cx2 + cy1*cy2 + cz1*cz2;
if( dp > 1.) dp = 1.; if( dp < -1.) dp = -1.;
dp = acos(dp);
r = cx1*x3 + cy1*y3 + cz1*z3;
if( r > 0 ) dp =  -dp ;
	return dp;
SKIP:
	return 0;
}
int set_torsion( ATOM *ap1, ATOM *ap2, ATOM *ap3, ATOM *ap4, float howmuch)
{
float nx,ny,nz;
float phi,cphi,sphi,xphi;
float rx,ry,rz, nnrx,nnry,nnrz, rnx,rny,rnz;
ATOM *ap,*b1,*b2,*a_next();
int numatom,a_number();
int i;
	numatom = a_number();
	b1 = ap2; b2 = ap3;
nx = b2->x - b1->x;
ny = b2->y - b1->y;
nz = b2->z - b1->z;
rx = sqrt(nx*nx + ny*ny + nz*nz);
if( rx < 1.e-6)
{aaerror(" bad torsion radius in set_torsion \n"); return 1;}
nx = nx/rx;
ny = ny/rx;
nz = nz/rx;
cphi = cos(howmuch); sphi = sin(howmuch);
	phi = (1.-cphi);
for( i=0; i< numatom; i++)
{
		ap = a_next(i);
		if( ap->gx > 0. && ap != b2 )
		{
rx = ap->x - b1->x;
ry = ap->y - b1->y;
rz = ap->z - b1->z;
xphi = nx*rx + ny*ry + nz*rz;
nnrx = xphi*nx;
nnry = xphi*ny;
nnrz = xphi*nz;
rnx = ny*rz - nz*ry;
rny = -nx*rz + nz*rx;
rnz = nx*ry - ny*rx;
rx = cphi*rx + phi*nnrx + sphi*rnx;
ry = cphi*ry + phi*nnry + sphi*rny;
rz = cphi*rz + phi*nnrz + sphi*rnz;
ap->x = rx + b1->x;
ap->y = ry + b1->y;
ap->z = rz + b1->z;
		}
	}
return 1;
}
#ifdef NEWCCALL
int tmap( FILE *op, int echo, int (*vfs[])(),int nfs,int i1,int i2,int i3,int i4,
int j1 , int j2 ,int j3, int j4 , int nistep, int njstep)
#else
int tmap(op,echo,vfs,nfs,i1,i2,i3,i4,j1,j2,j3,j4,nistep,njstep )
int i1,i2,i3,i4;
int j1,j2,j3,j4;
int nistep,njstep;
int (*vfs[])(),nfs;
FILE *op;
int echo;
#endif
{
	ATOM *ap, *a_next();
	int numatm,a_number();
	int i,j,ifs;
	float V;
	float x,dx,y,dy;
	numatm = a_number();
	if( numatm <5 ) return 1;
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	ap->vx = ap->x;
	ap->vy = ap->y;
	ap->vz = ap->z;
	}
	x = 0.;
	y = 0.;
	x = -3.141592653589793;
	dx = 0.;
	dy = 0.;
	if( nistep > 1)
	dx = 3.141592653589793*2./(nistep);
	if( njstep > 1)
	dy = 3.141592653589793*2./(njstep);
	fprintf(op,"%d %d Torsion map  %f %f steps\n",nistep,njstep,
		dx*180./3.141592653589793,dy*180./3.141592653589793);
	for( i=0; i< nistep; i++)
	{
	tset( op,0, i1,i2,i3,i4,x);
	y = 0.;
	y = -3.141592653589793;
	for( j=0; j< njstep; j++)
	{
		tset( op,0, j1,j2,j3,j4,y);
		V = 0.;
		for( ifs= 0; ifs< nfs; ifs++)
			(*vfs[ifs])(&V,0.);		
		fprintf(op,"%f ",V);	
		y = y + dy;
	}
	fprintf(op,"\n");
	x = x + dx;
	}
	for( i=0; i< numatm; i++)
	{
	ap = a_next(i);
	ap->x = ap->vx;
	ap->y = ap->vy;
	ap->z = ap->vz;
	}
return 1;
}
/* 当前文件是D:\Read\unonbon.c*/

#define ANSI 1
#ifdef ANSI
#endif
int u_v_nonbon( V, lambda )
	float *V,lambda;
{
	float r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	float rdebye;
	int inbond,inangle,i;
	ATOM *a1,*a2,*bonded[10],*angled[10];
	ATOM *a_next( );
	ATOM *(*use)[];
	int uselist(),nuse,used;
	ATOM *cp,*bp;
	int a_number(),inbuffer;
	float (*buffer)[],xx,yy,zz;
	int invector,atomsused,ii,jj,imax;
	float (*vector)[];
	ATOM *(*atms)[];
	float dielectric;
	cutoff = get_f_variable("cutoff");
	if( cutoff < 1.)
	{
		v_nonbon( V,lambda);
		return 1;
	}
	rdebye = cutoff/2.;
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	if( !uselist( &use,&nuse,cutoff) )return 0;
	i = a_number();
	buffer = malloc( 3*i*sizeof(float) );
	if( buffer == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	vector = malloc( i*sizeof(float) );
	if( vector == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	atms = malloc( i*sizeof(ATOM *) );
	if( atms == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	a1 = a_next(-1);
	a1 = a1->next;
	imax = a_number();
	used = 0;
	for( jj=1; jj<imax; jj++,a1=bp)
	{
	bp = a1->next;
	inbuffer = 0;
	if( (*use)[used] == a1)
	{ used += 1;}
	else { aaerror("error in uselist - must abort"); return 0;}
	while( (*use)[used] != a1)
	{
	  (*atms)[inbuffer++] = (*use)[used];
	  used += 1;
	}
	used += 1;
	if( inbuffer > 0)
	{
	for( i=0; i< inbuffer; i++)
	{
	(*buffer)[3*i  ] = (*atms)[i]->x;
	(*buffer)[3*i+1] = (*atms)[i]->y;
	(*buffer)[3*i+2] = (*atms)[i]->z;
	}
	if( lambda != 0.)
	{
	for( i=0; i< inbuffer; i++)
	{
		(*buffer)[3*i  ] = (*atms)[i]->x +(*atms)[i]->dx*lambda;	
		(*buffer)[3*i+1] = (*atms)[i]->y +(*atms)[i]->dy*lambda;	
		(*buffer)[3*i+2] = (*atms)[i]->z +(*atms)[i]->dz*lambda;	
	}
	}
	xx = a1->x + lambda*a1->dx;
	yy = a1->y + lambda*a1->dy;
	zz = a1->z + lambda*a1->dz;
	for( i=0;i< inbuffer; i++)
	{
	xt = xx - (*buffer)[3*i];
	yt = yy - (*buffer)[3*i+1];
	zt = zz - (*buffer)[3*i+2];
	r = xt*xt+yt*yt+zt*zt;
	if( r < 2.) r = 2.;
	r0 = sqrt(r); r = r*r*r ;
	(*vector)[i] = a1->q*(*atms)[i]->q/r0*dielectric*exp(-r0/rdebye)
		     - a1->a*(*atms)[i]->a/r
		     + a1->b*(*atms)[i]->b/r/r;
	}
	for(i=0; i< inbuffer; i++)
		*V += (*vector)[i];
	}
	}
	free( atms); free( buffer);
	free( vector);
	return 1;
}
int u_f_nonbon(lambda)
float lambda;
{
	float r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	float rdebye;
	int inbond,inangle,i;
	ATOM *a1,*a2,*bonded[10],*angled[10];
	ATOM *a_next( );
	ATOM *(*use)[];
	int uselist(),nuse,used;
	ATOM *cp,*bp;
	int a_number(),inbuffer;
	float (*buffer)[],xx,yy,zz,k;
	int invector,atomsused,ii,jj,imax;
	float (*vector)[];
	ATOM *(*atms)[];
	float dielectric;
	cutoff = get_f_variable("cutoff");
	if( cutoff < 1.)
	{
		f_nonbon( lambda);
		return 1;
	}
	rdebye = cutoff/2.;
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	if( !uselist( &use,&nuse,cutoff) )return 0;
	i = a_number();
	buffer = malloc( 3*i*sizeof(float) );
	if( buffer == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	vector = malloc( 3*i*sizeof(float) );
	if( vector == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	atms = malloc( i*sizeof(ATOM *) );
	if( atms == NULL)
	{ aaerror("cannot allocate memory in u_v_nonbon\n"); return 0;}
	a1 = a_next(-1);
	a1 = a1->next;
	imax = a_number();
	used = 0;
	for( jj=1; jj<imax; jj++,a1=bp)
	{
	bp = a1->next;
	inbuffer = 0;
	if( (*use)[used] == a1)
	{ used += 1;}
	else { aaerror("error in uselist - must abort"); return 0;}
	while( (*use)[used] != a1)
	{
	  (*atms)[inbuffer++] = (*use)[used];
	  used += 1;
	}
	used += 1;
	if( inbuffer > 0)
	{
	for( i=0; i< inbuffer; i++)
	{
	(*buffer)[3*i  ] = (*atms)[i]->x;
	(*buffer)[3*i+1] = (*atms)[i]->y;
	(*buffer)[3*i+2] = (*atms)[i]->z;
	}
	if( lambda != 0.)
	{
	for( i=0; i< inbuffer; i++)
	{
		(*buffer)[3*i  ] = (*atms)[i]->x +(*atms)[i]->dx*lambda;	
		(*buffer)[3*i+1] = (*atms)[i]->y +(*atms)[i]->dy*lambda;	
		(*buffer)[3*i+2] = (*atms)[i]->z +(*atms)[i]->dz*lambda;	
	}
	}
	xx = a1->x + lambda*a1->dx;
	yy = a1->y + lambda*a1->dy;
	zz = a1->z + lambda*a1->dz;
	for( i=0;i< inbuffer; i++)
	{
	xt = xx - (*buffer)[3*i];
	yt = yy - (*buffer)[3*i+1];
	zt = zz - (*buffer)[3*i+2];
	r = xt*xt+yt*yt+zt*zt;
	
	 if( r <= 1.)
	 { r = 1.; }
	r0 = sqrt(r); xt = xt/r0; yt = yt/r0; zt = zt/r0;
	 k = -a1->q*(*atms)[i]->q*dielectric*exp(-r0/rdebye)*
		(1./(rdebye*r0) +1./r) ;
	r = r*r*r;
	k += a1->a*(*atms)[i]->a/r/r0*6;
	k -= a1->b*(*atms)[i]->b/r/r/r0*12;
	(*vector)[3*i  ] = xt*k;
	(*vector)[3*i+1] = yt*k;
	(*vector)[3*i+2] = zt*k;
	}
	for(i=0; i< inbuffer; i++)
	{
		a1->fx -= (*vector)[3*i  ];
		a1->fy -= (*vector)[3*i+1];
		a1->fz -= (*vector)[3*i+2];
		(*atms)[i] ->fx += (*vector)[3*i  ];
		(*atms)[i] ->fy += (*vector)[3*i+1];
		(*atms)[i] ->fz += (*vector)[3*i+2];
	}
	}
	}
	free( atms); free( buffer);
	free( vector);
	return 1;
}
int uselist(  thelist,thesize, cutoff )
float cutoff;
int *thesize;
ATOM *(**thelist)[];
{
static int  oldatomnumber = 0;
static int  since = 0,lsize;
static ATOM *(*local)[];
static float oldcutoff = -1;
int a_number();
ATOM *a_next(),*a1,*a2,*ap,*bp;
int i,j,k,max;
int get_i_variable(),set_i_variable();
float lcutoff;
float x,y,z,r,rcut;
i = a_number();
j = get_i_variable("nbstep");
if( j <= 0) j= 10;
if( (i == oldatomnumber) && (since < j) && (cutoff == oldcutoff) )
{
	*thelist = local;
	*thesize = lsize;
	since += 1;
	return 1;
}
RESET:
if( oldatomnumber > 0) free(local);
oldcutoff = cutoff;
lcutoff = -cutoff;
since = 0;
oldatomnumber = i;
j = get_i_variable("nbdeep");
if( j<= 0) j = 20;
max = i*j;
local =  malloc( max*sizeof(ATOM * ) );
if( local == NULL )
{ aaerror("cannot allocate uselist memory"); exit(0);}
*thelist = local;
*thesize = 0;
rcut = cutoff*cutoff;
a1 = a_next(-1);
a1 = a1->next;
for( i=1; i< oldatomnumber; i++,a1=ap)
{
	ap = a1->next;
	(*local)[*thesize] = a1;
	*thesize += 1;
	a2 = a_next(-1);
	for( j=0;j<i; j++,a2=bp)
	{
	for(k=0; k< a1->dontuse; k++)
	{
		if( a2 == a1->excluded[k]) goto SKIP;
	}	
		if( (a2->x-a1->x) > cutoff) goto SKIP;
		if( (a2->x-a1->x) < lcutoff) goto SKIP;
		if( (a2->y-a1->y) > cutoff) goto SKIP;
		if( (a2->y-a1->y) < lcutoff) goto SKIP;
		if( (a2->z-a1->z) > cutoff) goto SKIP;
		if( (a2->z-a1->z) < lcutoff) goto SKIP;
	x = a2->x -a1->x;
	y = a2->y -a1->y;
	z = a2->z -a1->z;
	r = x*x + y*y + z*z;
	if( r > rcut) goto SKIP;
	
	(*local)[*thesize] = a2;
	*thesize += 1;
	if( *thesize >= max)
	{aaerror("please increase nbdeep (seti nbdeep (>20);)");
	 i = a_number();
	 j = get_i_variable("nbdeep");
	 if( j== 0) j = 20;
	 if( j == i+2)
	 {aaerror("Terrible error in uselist, too many interactions");
	  exit( 0) ; }
	 j = 2*j; if( j > i+2) j = i+2;
	 set_i_variable("nbdeep",j);
	 goto RESET;
	 }
SKIP:
	bp = a_next(1);
	}
	(*local)[*thesize] = a1;
	*thesize += 1;
	lsize = *thesize;
}
return 1;
}
/* 当前文件是D:\Read\variable.c*/

#define ANSI 1
#ifdef ANSI
#endif
#define NUM_SIG 6
#define NUM_TOT 7
#define INTEGER 0
#define FLOAT 1
typedef struct{
	int type;
	char name[NUM_TOT];
	union{  float f; int i;} value;
	void *next;
	}  VARIABLE;
VARIABLE *variableFIRST = NULL;
VARIABLE *variableLAST = NULL;
#define variableLONG sizeof(VARIABLE)
VARIABLE *match_variable( name )
	char *name;
{
	VARIABLE *vp;
	vp = variableFIRST;
	while(1 )
	{
		if( vp == NULL ) return vp;
		if( strcmp( &(vp->name[0]), name) == 0) return vp;
		if( vp == vp->next) return NULL;
		vp = vp->next;
	}
}
int set_f_variable( char *name, float f)
{
	VARIABLE *new,*match_variable();
	int i;
	
	new = match_variable( name);
if( new == NULL)
{
if( ( new = malloc( variableLONG ) ) == NULL)
{
return 0;
}
new->next = NULL;
if( variableFIRST == NULL) variableFIRST = new;
if( variableLAST == NULL) variableLAST = new;
	}
	new->value.f = f;
	new->type = FLOAT;
	for( i=0; i< NUM_TOT; i++)
	{
		new->name[i] = *name;
		if( *name == '\0') break;
		name++;
	}
	if( new->next == NULL)
{
new -> next = new;
variableLAST -> next = new;
variableLAST = new;
}
return 1;
}
int set_i_variable( name,f )
char *name;
int f;
{
	VARIABLE *new,*match_variable();
	int i;
	
	new = match_variable( name);
if( new == NULL)
{
if( ( new = malloc( variableLONG ) ) == NULL)
{
return 0;
}
new->next = NULL;
if( variableFIRST == NULL) variableFIRST = new;
if( variableLAST == NULL) variableLAST = new;
	}
	new->value.i = f;
	new->type = INTEGER ;
	for( i=0; i< NUM_TOT; i++)
	{
		new->name[i] = *name;
		if( *name == '\0') break;
		name++;
	}
	if( new->next == NULL)
{
new -> next = new;
variableLAST -> next = new;
variableLAST = new;
}
return 1;
}
float get_f_variable( name )
char *name;
{
	VARIABLE *vp;
	VARIABLE *match_variable();
	vp = match_variable(name);
	if( vp == NULL ) return 0.;
	if( vp->type == FLOAT) return vp->value.f ;
	return (float) vp->value.i;
}
int get_i_variable( name )
char *name;
{
	VARIABLE *vp;
	VARIABLE *match_variable();
	vp = match_variable(name);
	if( vp == NULL ) return 0;
	if( vp->type == INTEGER) return vp->value.i ;
	return (int) vp->value.f;
}
void dump_variable( FILE *where )
{
	VARIABLE *vp;
	vp = variableFIRST;
	while(1)
	{
	if( vp->next == NULL) return;
	if( vp->type == INTEGER)
	{
	fprintf(where,"seti %s %d ;\n",&vp->name[0],vp->value.i);
	} else
	{
	fprintf(where,"setf %s %f ;\n",&vp->name[0],vp->value.f);
	}
	if( vp->next == vp) return;
	vp = vp->next;
	}
}
/* 当前文件是D:\Read\vnonbon.c*/

void a_inactive_f_zero ();
#define ANSI 1
#ifdef ANSI
#endif
int fv_update_nonbon(  lambda )
	float lambda;
{
	float r,r0,xt,yt,zt;
	float k,k1,k2,k3,k4,k5;
	float ka3,ka2;
	float kb3,kb2;
	float get_f_variable();
	int inbond,inangle,i;
	ATOM *a1,*a2,*bonded[10],*angled[10];
	ATOM *a_next( );
	int (*indexes)[],inindex,in;
	int a_number();
	int ii,j,jj,imax,inclose;
	float (*vector)[];
	ATOM *close[NCLOSE],*(*atomall)[];
	float mxdq,dielectric,mxcut;
	static float dielecold = -1.;
	mxdq = get_f_variable("mxdq");
	mxcut = get_f_variable("mxcut");
	if( mxcut < 0.) mxcut= 5.;
	if( mxdq > 0.) mxdq = mxdq*mxdq;
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	if( dielecold != dielectric)
	{
	 dielecold = dielectric;
	mxdq = -1.;
	}
	dielectric = 332.17752/dielectric;
	
	i = a_number();
	vector = malloc( 4*i*sizeof(float) );
	if( vector == NULL)
	{ aaerror("cannot allocate memory in v_nonbon\n"); return 0;}
	atomall = malloc( i*sizeof(ATOM *) );
	if( atomall == NULL)
	{aaerror("cannot allocate memory in v_nonbon\n"); return 0;}
	imax = a_number();
	for( i=0; i< imax; i++)
	{
		(*atomall)[i] = a_next(i);
	}
	for( ii=0; ii< imax; ii++)
	{
a1 = (*atomall)[ii];
xt = a1->dx*lambda +a1->x - a1->px;
yt = a1->dy*lambda +a1->y - a1->py;
zt = a1->dz*lambda +a1->z - a1->pz;
r = xt*xt + yt*yt + zt*zt;
	if( r > mxdq ) goto DOIT;
	}
	
	free( vector);
	free (atomall);
	return 1;
DOIT:
	xt = get_f_variable("mmbox");
	if( xt > 0.)
	{ free(vector); free(atomall); mm_fv_update_nonbon(lambda); return 1;}
	indexes = malloc( imax* sizeof(int) );
	if( indexes == NULL ){
	aaerror(" cannot allocate memory in fv_update\n");
	return 0;}
	for( ii=0; ii< imax; ii++)
	{
	a1 = (*atomall)[ii];
	a1 -> VP = 0.;
	a1 -> dpx = 0.;
	a1 -> dpy = 0.;
	a1 -> dpz = 0.;
	a1 -> qxx = 0.;
	a1 -> qxy = 0.;
	a1 -> qxz = 0.;
	a1 -> qyy = 0.;
	a1 -> qyz = 0.;
	a1 -> qzz = 0.;
#ifdef CUBIC
	a1 -> qxxx = 0.;
	a1 -> qxxy = 0.;
	a1 -> qxxz = 0.;
	a1 -> qxyy = 0.;
	a1 -> qxyz = 0.;
	a1 -> qxzz = 0.;
	a1 -> qyyy = 0.;
	a1 -> qyyz = 0.;
	a1 -> qyzz = 0.;
	a1 -> qzzz = 0.;
#endif
	for( j=0; j< NCLOSE; j++)
		a1->close[j] = NULL;
	}
	for( ii=0; ii<  imax; ii++)
	{
	a1 = (*atomall)[ii];
	inclose = 0;
	if( lambda != 0.)
	{
	for( i=ii+1; i< imax; i++)
	{
	a2 = (*atomall)[i];
	j = i*4;
	(*vector)[j  ] = a2->x - a1->x + lambda*(a2->dx -a1->dx);
	(*vector)[j+1] = a2->y - a1->y + lambda*(a2->dy -a1->dy);
	(*vector)[j+2] = a2->z - a1->z + lambda*(a2->dz -a1->dz);
	}
	}else {
	for( i=ii+1; i< imax; i++)
	{
	a2 = (*atomall)[i];
	j = i*4;
	(*vector)[j  ] = a2->x - a1->x ;
	(*vector)[j+1] = a2->y - a1->y ;
	(*vector)[j+2] = a2->z - a1->z ;
	}
	}
	for( i=ii+1; i< imax; i++)
	{
		j = i*4;
		(*vector)[j+3] = sqrt((*vector)[j]*(*vector)[j] +
				 (*vector)[j+1]*(*vector)[j+1] +
				 (*vector)[j+2]*(*vector)[j+2]);
	}
	inindex = 0;
	for( i=ii+1; i< imax; i++)
	{
	a2 = (*atomall)[i];
	for( j=0; j< a1->dontuse; j++)
	{ if( a2 == a1->excluded[j]) goto SKIPNEW;}
	j = i*4;
	if( (*vector)[j+3] > mxcut || inclose > NCLOSE)
	{
	(*indexes)[inindex++] = i;
	}else {
	a1->close[inclose++] = (*atomall)[i];
	}
	if( inclose == NCLOSE)
	{
	aaerror(
	" fv_update_nonbon> too many atoms increase NCLOSE or decrease mxcut");
	}
SKIPNEW:   i = i;
	}
	
	for( in=0; in< inindex; in++)
	{
	i = (*indexes)[in];
	a2 = (*atomall)[i];
	j = i*4;
	r0 = one/(*vector)[j+3];
	r = r0*r0;
	r = r*r*r;
	xt = a1->q*a2->q*dielectric*r0;
	yt = a1->a*a2->a*r;
	zt = a1->b*a2->b*r*r;
	k = xt - yt + zt;
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	k1 = xt - yt*six + zt*twelve;
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	
	k2 = xt*three; ka2 = - yt*48.; kb2 =  zt*168.;
#ifdef CUBIC
	xt = xt*r0; yt = yt*r0; zt = zt*r0;
	k3 = -xt*5*3; ka3 =   yt*6*8*10 ; kb3 =  -zt*12*14*16;
#endif
	k1 = -k1;
	xt = (*vector)[j]*r0 ;
	yt = (*vector)[j+1]*r0 ;
	zt = (*vector)[j+2] *r0;
	
	a1->VP += k;
	a2->dpx -= k1*xt;
	a1->dpx += k1*xt;
	a2->dpy -= k1*yt;
	a1->dpy += k1*yt;
	a2->dpz -= k1*zt;
	a1->dpz += k1*zt;
	a2->qxx -= k2*(xt*xt - third) + ka2*(xt*xt - eightth) + kb2*(xt*xt-fourteenth) ;
	a1->qxx -= k2*(xt*xt - third) + ka2*(xt*xt - eightth) + kb2*(xt*xt-fourteenth) ;
	a2->qxy -= (k2+ka2+kb2)*yt*xt;
	a1->qxy -= (k2+ka2+kb2)*yt*xt;
	a2->qxz -= (k2+ka2+kb2)*zt*xt;
	a1->qxz -= (k2+ka2+kb2)*zt*xt;
	a2->qyy -= k2*(yt*yt - third) + ka2*(yt*yt - eightth) + kb2*(yt*yt-fourteenth) ;
	a1->qyy -= k2*(yt*yt - third) + ka2*(yt*yt - eightth) + kb2*(yt*yt-fourteenth) ;
	a2->qyz -= (k2+ka2+kb2)*yt*zt;
	a1->qyz -= (k2+ka2+kb2)*yt*zt;
	a2->qzz -= k2*(zt*zt - third) + ka2*(zt*zt - eightth) + kb2*(zt*zt-fourteenth) ;
	a1->qzz -= k2*(zt*zt - third) + ka2*(zt*zt - eightth) + kb2*(zt*zt-fourteenth) ;
#ifdef CUBIC
	a2->qxxx -= k3*(xt*xt*xt - xt*( 9./15 )) ;
	a2->qxxx -= ka3*(xt*xt*xt - xt*( 24./80 )) ;
	a2->qxxx -= kb3*(xt*xt*xt - xt*( 42./(14*16)));
	a1->qxxx += k3*(xt*xt*xt - xt*( 9./15 )) ;
	a1->qxxx += ka3*(xt*xt*xt - xt*( 24./80 )) ;
	a1->qxxx += kb3*(xt*xt*xt - xt*( 42./(14*16)));
	a2->qxxy -= k3*(yt*xt*xt - yt*( 6./ 15));
	a2->qxxy -= ka3*(yt*xt*xt - yt*( 11./ 80));
	a2->qxxy -= kb3*(yt*xt*xt - yt*( 17./ (14*16)));
	a1->qxxy += k3*(yt*xt*xt - yt*( 6./ 15));
	a1->qxxy += ka3*(yt*xt*xt - yt*( 11./ 80));
	a1->qxxy += kb3*(yt*xt*xt - yt*( 17./ (14*16)));
	a2->qxxz -= k3*(zt*xt*xt - zt*( 6./ 15));
	a2->qxxz -= ka3*(zt*xt*xt - zt*( 11./ 80));
	a2->qxxz -= kb3*(zt*xt*xt - zt*( 17./ (14*16)));
	a1->qxxz += k3*(zt*xt*xt - zt*( 6./ 15));
	a1->qxxz += ka3*(zt*xt*xt - zt*( 11./ 80));
	a1->qxxz += kb3*(zt*xt*xt - zt*( 17./ (14*16)));
	a2->qxyy -= k3*(yt*yt*xt - xt*( 6./ 15));
	a2->qxyy -= ka3*(yt*yt*xt - xt*( 11./ 80));
	a2->qxyy -= kb3*(yt*yt*xt - xt*( 17./ (14*16)));
	a1->qxyy += k3*(yt*yt*xt - xt*( 6./ 15));
	a1->qxyy += ka3*(yt*yt*xt - xt*( 11./ 80));
	a1->qxyy += kb3*(yt*yt*xt - xt*( 17./ (14*16)));
	a2->qxyz -= (k3+ka3+kb3)*yt*zt*xt;
	a1->qxyz += (k3+ka3+kb3)*yt*zt*xt;
	a2->qxzz -= k3*(zt*zt*xt - xt*( 6./ 15));
	a2->qxzz -= ka3*(zt*zt*xt - xt*( 11./ 80));
	a2->qxzz -= kb3*(zt*zt*xt - xt*( 17./ (14*16)));
	a1->qxzz += k3*(zt*zt*xt - xt*( 6./ 15));
	a1->qxzz += ka3*(zt*zt*xt - xt*( 11./ 80));
	a1->qxzz += kb3*(zt*zt*xt - xt*( 17./ (14*16)));
	a2->qyyy -= k3*(yt*yt*yt - yt*( 9./15 )) ;
	a2->qyyy -= ka3*(yt*yt*yt - yt*( 24./80 )) ;
	a2->qyyy -= kb3*(yt*yt*yt - yt*( 42./(14*16)));
	a1->qyyy += k3*(yt*yt*yt - yt*( 9./15 )) ;
	a1->qyyy += ka3*(yt*yt*yt - yt*( 24./80 )) ;
	a1->qyyy += kb3*(yt*yt*yt - yt*( 42./(14*16)));
	a2->qyyz -= k3*(yt*yt*zt - zt*( 6./ 15));
	a2->qyyz -= ka3*(yt*yt*zt - zt*( 11./ 80));
	a2->qyyz -= kb3*(yt*yt*zt - zt*( 17./ (14*16)));
	a1->qyyz += k3*(yt*yt*zt - zt*( 6./ 15));
	a1->qyyz += ka3*(yt*yt*zt - zt*( 11./ 80));
	a1->qyyz += kb3*(yt*yt*zt - zt*( 17./ (14*16)));
	a2->qyzz -= k3*(zt*zt*yt - yt*( 6./ 15));
	a2->qyzz -= ka3*(zt*zt*yt - yt*( 11./ 80));
	a2->qyzz -= kb3*(zt*zt*yt - yt*( 17./ (14*16)));
	a1->qyzz += k3*(zt*zt*yt - yt*( 6./ 15));
	a1->qyzz += ka3*(zt*zt*yt - yt*( 11./ 80));
	a1->qyzz += kb3*(zt*zt*yt - yt*( 17./ (14*16)));
	a2->qzzz -= k3*(zt*zt*zt - zt*( 9./15 )) ;
	a2->qzzz -= ka3*(zt*zt*zt - zt*( 24./80 )) ;
	a2->qzzz -= kb3*(zt*zt*zt - zt*( 42./(14*16)));
	a1->qzzz += k3*(zt*zt*zt - zt*( 9./15 )) ;
	a1->qzzz += ka3*(zt*zt*zt - zt*( 24./80 )) ;
	a1->qzzz += kb3*(zt*zt*zt - zt*( 42./(14*16)));
#endif
	}
	
	a1->px = a1->dx*lambda + a1->x;
	a1->py = a1->dy*lambda + a1->y;
	a1->pz = a1->dz*lambda + a1->z;
	}
	
	a_inactive_f_zero();
	free( indexes);
	free( vector);
	free (atomall);
	return 1;
}
int f_nonbon(lambda)
float lambda;
{
	float ux,uy,uz;
	float k,r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	int inbond,inangle,i,test;
	ATOM *a1,*a2,*bonded[10],*angled[10];
	ATOM *a_next( );
	int a_number(),inbuffer,imax;
	float (*buffer)[];
	int invector,atomsused,ii,jj;
	float (*vector)[];
	ATOM *(*atms)[],*(*atomall)[];
float dielectric;
	float fx,fy,fz;
	float xt2,xt3,xt4;
	float yt2,yt3,yt4;
	float zt2,zt3,zt4;
	fv_update_nonbon( lambda);
dielectric = get_f_variable("dielec");
if( dielectric < 1.) dielectric = 1.;
dielectric = 332.17752/dielectric;
i = a_number();
atomall = malloc( i*sizeof(ATOM *) );
if( atomall == NULL)
{aaerror("cannot allocate memory in f_nonbon"); return 0;}
imax = a_number();
for( i=0; i< imax; i++)
{
(*atomall)[i] = a_next(i);
}
for( i= 0; i< imax; i++)
{
	fx = 0.; fy = 0.; fz = 0.;
a1 = (*atomall)[i];
xt = a1->dx*lambda +a1->x - a1->px;
yt = a1->dy*lambda +a1->y - a1->py;
zt = a1->dz*lambda +a1->z - a1->pz;
fx = (a1->qxx*xt + a1->qxy*yt
+ a1->qxz*zt) ;
fy = (a1->qxy*xt + a1->qyy*yt
+ a1->qyz*zt) ;
fz = (a1->qxz*xt + a1->qyz*yt
+ a1->qzz*zt) ;
#ifdef CUBIC
	xt2 = xt*xt; yt2 = yt*yt; zt2 = zt*zt;
	fx += a1->qxxx*xt2/2. + a1->qxxy*xt*yt + a1->qxxz*xt*zt
		+ a1->qxyy*yt/2. + a1->qxyz*yt*zt + a1->qxzz*zt2/2.;
	fy += a1->qxxy*xt2/2. + a1->qxyy*xt*yt + a1->qxyz*xt*zt
		+ a1->qyyy*yt/2. + a1->qyyz*yt*zt + a1->qyzz*zt2/2.;
	fz += a1->qxxz*xt2/2. + a1->qxyz*xt*yt + a1->qxzz*xt*zt
		+ a1->qyyz*yt/2. + a1->qyzz*yt*zt + a1->qzzz*zt2/2.;
#endif
#ifdef QUARTIC
	xt3 = xt*xt2; yt3 = yt*yt2; zt3 = zt*zt2;
	fx +=  a1->qxxxx*xt3/6. + a1->qxxxy*xt2*yt/2. + a1->qxxxz*xt2*zt/2.
		+ a1->qxxyy*xt*yt/2. + a1->qxxyz*xt*yt*zt + a1->qxxzz*xt*zt2/2.
		+ a1->qxyyy*yt3/6. + a1->qxyyz*yt2*zt/2. + a1->qxyzz*yt*zt2/2.
		+ a1->qxzzz*zt3/6.;
	fy +=  a1->qxxxy*xt3/6. + a1->qxxyy*xt2*yt/2. + a1->qxxyz*xt2*zt/2.
		+ a1->qxyyy*xt*yt/2. + a1->qxyyz*xt*yt*zt + a1->qxyzz*xt*zt2/2.
		+ a1->qyyyy*yt3/6. + a1->qyyyz*yt2*zt/2. + a1->qyyzz*yt*zt2/2.
		+ a1->qyzzz*zt3/6.;
	fz +=  a1->qxxxz*xt3/6. + a1->qxxyz*xt2*yt/2. + a1->qxxzz*xt2*zt/2.
		+ a1->qxyyz*xt*yt/2. + a1->qxyzz*xt*yt*zt + a1->qxzzz*xt*zt2/2.
		+ a1->qyyyz*yt3/6. + a1->qyyzz*yt2*zt/2. + a1->qyzzz*yt*zt2/2.
		+ a1->qzzzz*zt3/6.;
#endif
#ifdef QUINTIC
	xt4 = xt*xt3; yt4 = yt*yt3; zt4 = zt*zt3;
	fx += a1->qxxxxx*xt4/24. + a1->qxxxxy*xt3*yt/6. + a1->qxxxxz*xt3*zt/6.
		+ a1->qxxxyy*xt2*yt2/4. + a1->qxxxyz*xt2*yt*zt/2. + a1->qxxxzz*xt2*zt2/4.
		+ a1->qxxyyy*xt*yt3/6. + a1->qxxyyz*xt*yt2*zt/2. + a1->qxxyzz*xt*yt*zt2/2.
		+ a1->qxxzzz*xt*zt3/6. + a1->qxyyyy*yt4/24. + a1->qxyyyz*yt3*zt/6.
		+ a1->qxyyzz*yt2*zt2/4. + a1->qxyzzz*yt*zt3/6. + a1->qxzzzz*zt4/24.;
	fy += a1->qxxxxy*xt4/24. + a1->qxxxyy*xt3*yt/6. + a1->qxxxyz*xt3*zt/6.
		+ a1->qxxyyy*xt2*yt2/4. + a1->qxxyyz*xt2*yt*zt/2. + a1->qxxyzz*xt2*zt2/4.
		+ a1->qxyyyy*xt*yt3/6. + a1->qxyyyz*xt*yt2*zt/2. + a1->qxyyzz*xt*yt*zt2/2.
		+ a1->qxyzzz*xt*zt3/6. + a1->qyyyyy*yt4/24. + a1->qyyyyz*yt3*zt/6.
		+ a1->qyyyzz*yt2*zt2/4. + a1->qyyzzz*yt*zt3/6. + a1->qyzzzz*zt4/24.;
	fz += a1->qxxxxz*xt4/24. + a1->qxxxyz*xt3*yt/6. + a1->qxxxzz*xt3*zt/6.
		+ a1->qxxyyz*xt2*yt2/4. + a1->qxxyzz*xt2*yt*zt/2. + a1->qxxzzz*xt2*zt2/4.
		+ a1->qxyyyz*xt*yt3/6. + a1->qxyyzz*xt*yt2*zt/2. + a1->qxyzzz*xt*yt*zt2/2.
		+ a1->qxzzzz*xt*zt3/6. + a1->qyyyyz*yt4/24. + a1->qyyyzz*yt3*zt/6.
		+ a1->qyyzzz*yt2*zt2/4. + a1->qyzzzz*yt*zt3/6. + a1->qzzzzz*zt4/24.;
#endif
	a1->fx += fx  + a1->dpx;
	a1->fy += fy  + a1->dpy;
	a1->fz += fz  + a1->dpz;
	for( jj=0; jj< NCLOSE; jj++)
	{ if( a1->close[jj] == NULL) break; }
for( ii=0; ii< jj;ii++)
{
a2 = a1->close[ii];
ux = (a2->dx -a1->dx)*lambda +(a2->x -a1->x);
uy = (a2->dy -a1->dy)*lambda +(a2->y -a1->y);
uz = (a2->dz -a1->dz)*lambda +(a2->z -a1->z);
r =one/( ux*ux + uy*uy + uz*uz); r0 = sqrt(r);
ux = ux*r0; uy = uy*r0; uz = uz*r0;
k = -dielectric*a1->q*a2->q*r;
r = r*r*r;
k += a1->a*a2->a*r*r0*six;
k -= a1->b*a2->b*r*r*r0*twelve;
a1->fx += ux*k;
a1->fy += uy*k;
a1->fz += uz*k;
a2->fx -= ux*k;
a2->fy -= uy*k;
a2->fz -= uz*k;
}
}
	a_inactive_f_zero();
free( atomall); return 1;
}
int v_nonbon( V, lambda )
float *V,lambda;
{
float r,r0,xt,yt,zt;
float get_f_variable();
float k;
int inbond,inangle,i;
ATOM *a1,*a2,*bonded[10],*angled[10];
ATOM *a_next( );
int a_number(),inbuffer;
int invector,atomsused,ii,jj,imax;
float (*vector)[];
float vx;
float k2;
ATOM *(*atomall)[];
float dielectric;
	float xt2,xt3,xt4,xt5;
	float yt2,yt3,yt4,yt5;
	float zt2,zt3,zt4,zt5;
	fv_update_nonbon( lambda);
dielectric = get_f_variable("dielec");
if( dielectric < 1.) dielectric = 1.;
dielectric = 332.17752/dielectric;
i = a_number();
atomall = malloc( i*sizeof(ATOM *) );
if( atomall == NULL)
{aaerror("cannot allocate memory in v_nonbon"); return 0;}
imax = a_number();
for( i=0; i< imax; i++)
{
(*atomall)[i] = a_next(i);
}
for( i= 0; i< imax; i++)
{
a1 = (*atomall)[i];
		vx = a1->VP;
xt = a1->dx*lambda +a1->x - a1->px;
yt = a1->dy*lambda +a1->y - a1->py;
zt = a1->dz*lambda +a1->z - a1->pz;
vx -= (a1->dpx*xt + a1->dpy*yt
+ a1->dpz*zt) ;
vx -= ( (xt*(.5*a1->qxx*xt + a1->qxy*yt + a1->qxz*zt)
+ yt*(.5*a1->qyy*yt + a1->qyz*zt) + .5*zt*a1->qzz*zt));
#ifdef CUBIC
		xt2 = xt*xt; yt2 = yt*yt;  zt2 = zt*zt;
		xt3 = xt2*xt; yt3 = yt2*yt; zt3 = zt2*zt;
	vx -= a1->qxxx*xt3/6. + a1->qxxy*xt2*yt/2 + a1->qxxz*xt2*zt/2
		+ a1->qxyy*xt*yt2/2 + a1->qxyz*xt*yt*zt + a1->qxzz*xt*zt2/2
		+ a1->qyyy*yt3/6 + a1->qyyz*yt2*zt/2 + a1->qyzz*yt*zt2/2
		+ a1->qzzz*zt3/6.;
#endif
#ifdef QUARTIC
		xt4 = xt3*xt; yt4 = yt3*yt; zt4 = zt3*zt;
	vx -= a1->qxxxx*xt4/24. + a1->qxxxy*xt3*yt/6. + a1->qxxxz*xt3*yt/6. + a1->qxxyy*xt2*yt2/4.
		+ a1->qxxyz*xt2*yt*zt/2. + a1->qxxzz*xt2*zt2/4. + a1->qxyyy*xt*yt3/6.
		+ a1->qxyyz*xt*yt2*zt/2. + a1->qxyzz*xt*yt*zt2/2. + a1->qxzzz*xt*zt3/6.
		+ a1->qyyyy*yt4/24. + a1->qyyyz*yt3*zt/6. + a1->qyyzz*yt2*zt2/4. + a1->qyzzz*yt*zt3/6.
		+ a1->qzzzz*zt4/24.;
#endif
#ifdef QUINTIC
		xt5 = xt4*xt; yt5 = yt4*yt; zt5 = zt4*zt;
	vx -= a1->qxxxxx*xt5/120. + a1->qxxxxy*xt4*yt/24. + a1->qxxxxz*xt4*zt/24.
		+ a1->qxxxyy*xt3*yt2/12. + a1->qxxxyz*xt3*yt*zt/6. + a1->qxxxzz*xt3*zt2/12.
		+ a1->qxxyyy*xt2*yt3/12. + a1->qxxyyz*xt2*yt2*zt/4. + a1->qxxyzz*xt2*yt*zt2/4.
		+ a1->qxxzzz*xt2*zt3/12. + a1->qxyyyy*xt*yt4/24.  + a1->qxyyyz*xt*yt3*zt/6.
		+ a1->qxyyzz*xt*yt2*zt2/4. + a1->qxyzzz*xt*yt*zt3/6. + a1->qxzzzz*xt*zt4/24.
		+ a1->qyyyyy*yt5/120. + a1->qyyyyz*yt4*zt/24 + a1->qyyyzz*yt3*zt2/12.
		+ a1->qyyzzz*yt2*zt3/12. + a1->qyzzzz*yt*zt4/24. + a1->qzzzzz*zt5/120.;
#endif
	for( jj=0; jj< NCLOSE; jj++)
	{ if( a1->close[jj] == NULL) break; }
for( ii=0; ii< jj;ii++)
{
a2 = a1->close[ii];
xt = (a2->dx -a1->dx)*lambda +(a2->x -a1->x);
yt = (a2->dy -a1->dy)*lambda +(a2->y -a1->y);
zt = (a2->dz -a1->dz)*lambda +(a2->z -a1->z);
r = one/(xt*xt + yt*yt + zt*zt); r0 = sqrt(r);
k = dielectric*a1->q*a2->q*r0;
r = r*r*r;
k -= a1->a*a2->a*r;
k += a1->b*a2->b*r*r;
	vx += k;
}
*V += vx;
	}
	a_inactive_f_zero();
free( atomall); return 1;
}
int zone_nonbon( V, lambda ,alist, inalist )
	float *V,lambda;
	ATOM *( *alist)[] ;
	int inalist;
{
	float r,r0,xt,yt,zt;
	float lcutoff,cutoff,get_f_variable();
	int inbond,inangle,i,ii;
	ATOM *a1,*a2;
	ATOM *a_next( );
	float dielectric,ve,va,vh;
	ATOM *a_m_serial();
	if( inalist <= 0 ) return 1;
	dielectric = get_f_variable("dielec");
	if( dielectric < 1.) dielectric = 1.;
	dielectric = 332.17752/dielectric;
	cutoff = get_f_variable("cutoff");
	if( cutoff < 1.) cutoff = 1.e10;
	lcutoff = -cutoff;
	for( ii=0; ii< inalist; ii++)
	{
	a1 = (*alist)[ii];
	if( a1 == NULL ) goto NOTANATOM;
	ve = 0.; va = 0.; vh = 0.;
	a2 = a_next(-1);
	while(  (a2 != NULL) && (a2->next != NULL) && a2->next != a2)
	{
	if( a2 == a1) goto SKIP;
	for(i = 0; i< a1->dontuse; i++)
		if( a2 == a1->excluded[i]) goto SKIP;
	xt = (a1->x -a2->x) + lambda*(a1->dx - a2->dx);
	if( (xt > cutoff) || (xt < lcutoff) ) goto SKIP;
	yt = (a1->y -a2->y) + lambda*(a1->dy - a2->dy);
	if( (yt > cutoff) || (yt < lcutoff) ) goto SKIP;
	zt = (a1->z -a2->z) + lambda*(a1->dz - a2->dz);
	if( (zt > cutoff) || (zt < lcutoff) ) goto SKIP;
	r = xt*xt+yt*yt+zt*zt;
	if( r < 1.) r = 1.;
	r0 = sqrt(r); r = r*r*r ;
	ve += dielectric*a1->q*a2->q/r0;
	va -= a1->a*a2->a/r;
	vh += a1->b*a2->b/r/r;
SKIP:
	if( a2->next == a2) break;
	a2 = a2->next;
	}
	*V += ve + va + vh;
NOTANATOM:
	i = i;
	}
	return 1;
}
