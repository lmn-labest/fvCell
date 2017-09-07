#include<Properties.h>

/*********************************************************************
 * Data de criacao    : 29/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * IDEALGASDENSITY: kg/(m^3)                                         *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em kelvin                                         *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE airDensity(DOUBLE const t,bool const fKelvin) {

  DOUBLE tc,d;
  
  if(fKelvin)
    tc = t;  
  else
    tc = CELSIUS_FOR_KELVIN(t);  

  d = (MMOLARAR*PREREF)/(IDEALGASR*tc);

  return d;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 29/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * AIRSPECIFIHEAT: kJ/(kg.K)                                         *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em Kelvin                                         *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE airSpecifiHeat(DOUBLE const t,bool const fKelvin) {

  short i,n=sHeat.nPol;  
  DOUBLE a[10],y,d;
  DOUBLE tc;

  if(fKelvin)
    tc = t;  
  else
    tc = CELSIUS_FOR_KELVIN(t);  

  for (i = 0; i < n; i++)
    a[i] = sHeat.a[i];
  
/*... polinomio*/
  y = a[0];
  for (i = 1; i < n; i++)
    y += a[i]*pow(tc,i);
/*.....................................................................*/

  if (y < 0) {
    printf("Calor especifico negativo temp: %lf\n!!",tc);
    exit(EXIT_FAILURE);
  }

/*...*/
  d = 1.e+0;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 29/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * AIRDYNAMICVISCOSITY: kJ/(kg.K)                                    *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em Kelvin                                         *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE airDynamicViscosity(DOUBLE const t,bool const fKelvin) {

  DOUBLE a[6],x[5],y,d;
  DOUBLE tc;

  if(fKelvin)
    tc = t;  
  else
    tc = CELSIUS_FOR_KELVIN(t);  

  a[0] = 1.01715208657198E-04;
  a[1] =-1.11853193802525E-06;
  a[2] = 5.13828104260976E-09;
  a[3] =-1.17795003220707E-11;
  a[4] = 1.32665295560992E-14;
  a[5] =-5.84123566384409E-18;

/*... t */  
  x[0] = tc;
/*... t^2 */
  x[1] = tc*tc;
/*... t^3 */
  x[2] = tc*x[1];
/*... t^4 */
  x[3] = tc*x[2];
/*... t^5 */
  x[4] = tc*x[3];
  
/*... polinomio*/
  y = a[0] + a[1]*x[0] + a[2]*x[1] + a[3]*x[2] + a[4]*x[3] + a[5]*x[4];
/*.....................................................................*/

  if (y < 0) {
    printf("Viscosidade dinamica negativa temp: %lf\n!!",tc);
    exit(EXIT_FAILURE);
  }

/*...*/
  d = 1.e0;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 28/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * AIRTHERMALCONDUCTITY: [KW/m.K]                                    *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em kelvin                                         *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *                                                                   *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE airThermalConductvity(DOUBLE const t,bool const fKelvin) {

  DOUBLE a[6],x[5],y,d;
  DOUBLE tc;

  if(fKelvin)
    tc = t;  
  else
    tc = CELSIUS_FOR_KELVIN(t);  

  a[0] =-4.18269223884387E-03;
  a[1] = 1.64562119970664E-04;
  a[2] =-3.84678212644587E-07;
  a[3] = 7.78532588867624E-10;
  a[4] =-7.49481811253193E-13;
  a[5] = 2.57602368857936E-16;
;

/*... t */  
  x[0] = tc;
/*... t^2 */
  x[1] = tc*tc;
/*... t^3 */
  x[2] = tc*x[1];
/*... t^4 */
  x[3] = tc*x[2];
/*... t^5 */
  x[4] = tc*x[3];
  
/*... polinomio*/
  y = a[0] + a[1]*x[0]+ a[2]*x[1] + a[3]*x[2] + a[4]*x[3] + a[5]*x[4];
/*.....................................................................*/

  if (y < 0) {
    printf("Condutividade termica negativa temp: %lf\n!!",tc);
    exit(EXIT_FAILURE);
  }

/*...*/
  d = 1.e-3;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 28/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * TEMPFORSPECIFICENTHALPY: calcula a entalpia espeficia apartir da  *
 * temperatura                                                       *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura                                                   *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE tempForSpecificEnthalpy(DOUBLE const t,bool const fKelvin) {

  short i,n=sHeat.nPol;
  DOUBLE a[6],d,dt,tmp;
  DOUBLE tc,tRef= TREF ;

  if(fKelvin)
    tc = t;  
  else
    tc = CELSIUS_FOR_KELVIN(t);  

  for (i = 0; i < n; i++)
    a[i] = sHeat.a[i];

  tmp = 0.0;
  for (i = 0; i < n; i++) {
    d    = (double) (i + 1);
    dt   = tc-tRef;
    tmp += a[i]*pow(dt,d)/d;
  }
  
  return tmp;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 28/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * SPECIFICENTHALPYFORTEMP:  calcula a temperatura apartir da        *
 * entalpia especifica                                               * 
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t -                                                               *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE specificEnthalpyForTemp(DOUBLE const hs,bool const fKelvin) {

  unsigned short i;
  bool flag = false;
  DOUBLE f,fl,t,conv,tol=1e-10;
 
  t    = 0.e0;
  conv = (hs-tempForSpecificEnthalpy(t,true))*tol;
  conv = fabs(conv);
/*... Newton-Raphson*/
  for(i=0;i<60000;i++){
    f  = hs-tempForSpecificEnthalpy(t,true);
    if(fabs(f) < conv ) {
      flag = true;
      break;
    }
    
    fl = airSpecifiHeat(t,true);
    t += f/fl;   
  }
/*...................................................................*/

  if(!flag){
    printf("%i %e %e %e\n",i,t,f,conv);
    ERRO_GERAL(__FILE__,__func__,__LINE__,
    "temperature->sEnthalpy:\n Newton-raphson did not converge !!");
  }

  if(!fKelvin)
    t = KELVIN_FOR_CELSIUS(t);  

  return t;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * WATERDESNITY: kg/(m^3)                                            *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em �C                                             *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE waterDensity(DOUBLE const t) {

  DOUBLE a,b,c,d;
  DOUBLE tmp1,tmp2,tmp3,tmp4;

  a = 288.9414e0;
  b = 508929.2e0;
  c = 68.12963e0;
  d = 3.9863e0;
  
  tmp1 = t + a;
  tmp2 = b*(t+c);
  tmp3 = (t-d)*(t-d);  

  tmp4 =  1.e0 - tmp1/tmp2*tmp3;
  
  if (tmp4 < 0) {
    printf("Massa especifica negativa\n!!");
    exit(EXIT_FAILURE);
  }

  return 1000.e0*tmp4;


}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * WATERSPECIFIHEAT: kJ/(kg.�C)                                      *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em �C                                             *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *                                                                   *
 * range  T=]0,100[                                                  * 
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE waterSpecifiHeat(DOUBLE const t) {

  DOUBLE a[5],x[4],y,d;

  a[0] = 4.21470622853361e+00;
  a[1] =-2.87563217630463e-03;
  a[2] = 7.57667401959410e-05;
  a[3] =-7.93659500485961e-07;
  a[4] = 3.28899958033620e-09;

/*... t */  
  x[0] = t;
/*... t*t */
  x[1] = t*t;
/*... t*t*t */
  x[2] = t*x[1];
/*... t*t*t*t */
  x[3] = t*x[2];
  
/*... polinomio*/
  y = a[0] + a[1]*x[0] + a[2]*x[1] + a[3]*x[2] + a[4]*x[3];
/*.....................................................................*/

  if (y < 0) {
    printf("Calor especifico negativo\n!!");
    exit(EXIT_FAILURE);
  }

/*...*/
  y = d = 1.e0;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * WATERDINAMICVICOSITY: Kg/(m.s)                                    *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em �C                                             *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *                                                                   *
 * range  T=]0,100[                                                  * 
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE waterDynamicViscosity(DOUBLE const t) {

  DOUBLE a[5],x[4],y,d;

  a[0] = 1.75373877709050e+00;
  a[1] =-5.20548110460391e-02;
  a[2] = 8.73350059860241e-04;
  a[3] =-7.60339598706936e-06;
  a[4] = 2.60693147656508e-08;

/*... t */  
  x[0] = t;
/*... t*t */
  x[1] = t*t;
/*... t*t*t */
  x[2] = t*x[1];
/*... t*t*t*t */
  x[3] = t*x[2];
  
/*... polinomio*/
  y = a[0] + a[1]*x[0] + a[2]*x[1] + a[3]*x[2] + a[4]*x[3];
/*.....................................................................*/
  
   if (y < 0) {
    printf("Visosidade dinamica negativa\n!!");
    exit(EXIT_FAILURE);
  }

/*...*/
  d = 1.e-3;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 28/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * WATERTHERMALCONDUCTITY: [W/m.K]                                   *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 * t - temperatura em �C                                             *
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *                                                                   *
 * range  T=]0,100[                                                  * 
 *-------------------------------------------------------------------*
 *********************************************************************/
DOUBLE waterThermalConductvity(DOUBLE const t) {

  DOUBLE a[5],x[4],y,d;

  a[0] = 0.5706e+00;
  a[1] = 1.756e-03;
  a[2] = 6.46e-06;

/*... t */  
  x[0] = t;
/*... t*t */
  x[1] = t*t;
  
/*... polinomio*/
  y = a[0] + a[1]*x[0] + a[2]*x[1];
/*.....................................................................*/
  
   if (y < 0) {
    printf("Condutividade termica negativa\n!!");
    exit(EXIT_FAILURE);
  }

/*...*/
  d = 1.e-3;
/*.....................................................................*/

  return d*y;

}
/**********************************************************************/

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * UPDATEDENSITY:                                                    *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void updateDensity(DOUBLE *RESTRICT temp     ,DOUBLE *RESTRICT density
                  ,bool const iKelvin    
                  ,INT const nEl             ,char  const iCod)

{
  INT i;
  short nD = DENSITY_LEVEL;

/*...*/
  switch (iCod){
    case PROP_UPDATE_SIMPLE_LOOP:
      for(i=0;i<nEl;i++){
/*...*/           
        MAT2D(i,2 ,density ,nD) = airDensity(temp[i],iKelvin);
      }
/*..................................................................*/
    break;  

  case PROP_UPDATE_OLD_TIME:
    for(i=0;i<nEl;i++){
/*...t(n-2) = t(n-1)*/
      MAT2D(i,0 ,density ,nD) = MAT2D(i,1 ,density ,nD);
/*...t(n-1) = t(n)*/           
      MAT2D(i,1 ,density ,nD) = MAT2D(i,2 ,density ,nD);
    }
/*..................................................................*/
    break;
  }
/*..................................................................*/


}
/*********************************************************************/ 

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * UPDATESPECIFICHEAT:                                               *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void updateSpecificHeat(DOUBLE *RESTRICT temp,DOUBLE *RESTRICT sHeat
                       ,bool const iKelvin 
                       ,INT const nEl        ,char  const iCod)

{
  INT i;
  short nD = SHEAT_LEVEL;
/*...*/
  switch (iCod){
    case PROP_UPDATE_SIMPLE_LOOP:
      for(i=0;i<nEl;i++)
/*...*/           
        MAT2D(i,2 ,sHeat ,nD) =  airSpecifiHeat(temp[i],iKelvin);
/*..................................................................*/
    break;  

  case PROP_UPDATE_OLD_TIME:
    for(i=0;i<nEl;i++){
/*...*/
      MAT2D(i,0 ,sHeat ,nD) = MAT2D(i,1 ,sHeat ,nD);           
      MAT2D(i,1 ,sHeat ,nD) = MAT2D(i,2 ,sHeat ,nD);
    }
/*..................................................................*/
    break;
  }
/*..................................................................*/


}
/*********************************************************************/

/*********************************************************************
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * UPDATESPECIFICHEAT:                                               *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void updateThermalCondutivty(DOUBLE *RESTRICT t,DOUBLE *RESTRICT thCond   
                            ,bool const iKelvin,INT const nEl)

{
  INT i;

  for(i=0;i<nEl;i++)         
    thCond[i] = airThermalConductvity(t[i],iKelvin);

}
/*********************************************************************/

/*********************************************************************
 * Data de criacao    : 01/09/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * UPDATESPECIFICHEAT:                                               *
 *-------------------------------------------------------------------*
 * Parametros de entrada:                                            *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * Parametros de saida:                                              *
 *-------------------------------------------------------------------*
 *-------------------------------------------------------------------*
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void updateDynamicViscosity(DOUBLE *RESTRICT temp,DOUBLE *RESTRICT visc    
                          ,bool const iKelvin    ,INT const nEl)

{
  INT i;

  for(i=0;i<nEl;i++)         
    visc[i] = airDynamicViscosity(temp[i],iKelvin);

}
/*********************************************************************/

/********************************************************************* 
 * Data de criacao    : 27/08/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * INITPROPTEMP: inicializao de propriedades com variacao temporal da*
 * dependentes da temperatura                                        *
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * prop    -> nao definido                                           * 
 * t       -> temperatura                                            *
 * propMat -> propriedade de referencia por material                 * 
 * mat     -> material por celula                                    * 
 * np      -> numero niveis de tempos                                * 
 * nCell   -> numero de celulas                                      * 
 * iKelvin -> temperatura em kelvin (true|false)                     *
 * iProp   -> numero da propriedade                                  * 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 * prop    -> propriedade iniciacializada                            * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              * 
 *-------------------------------------------------------------------* 
  *********************************************************************/
void initPropTemp(DOUBLE *RESTRICT prop   ,DOUBLE *RESTRICT t 
                 ,DOUBLE *RESTRICT propMat,short *RESTRICT mat
                 ,short const np          ,INT    const nCell 
                 ,bool const iKelvin      ,short const iProp)
{    
  INT i;
  unsigned short j,lMat;         
  for(i=0;i<nCell;i++){    

/*...*/
    lMat               = mat[i]-1;
/*...................................................................*/

/*...*/
    if( iProp == DENSITY )
      MAT2D(lMat,iProp,propMat,MAXPROP) = airDensity(t[i],iKelvin);
/*...................................................................*/

/*...*/
    else if( iProp == SPECIFICHEATCAPACITYFLUID)  
      MAT2D(lMat,iProp,propMat,MAXPROP) 
      = airSpecifiHeat(t[i],iKelvin);
/*...................................................................*/

/*...*/
    else if( iProp == DYNAMICVISCOSITY)  
      MAT2D(lMat,iProp,propMat,MAXPROP) 
      = airDynamicViscosity(t[i],iKelvin);
/*...................................................................*/

/*...*/
    else if( iProp == THERMALCONDUCTIVITY)  
      MAT2D(lMat,iProp,propMat,MAXPROP) 
      = airThermalConductvity(t[i],iKelvin);
/*...................................................................*/

/*...*/
    for(j=0;j<np;j++)      
      MAT2D(i,j,prop,np) = MAT2D(lMat,iProp,propMat,MAXPROP); 
/*...................................................................*/
  
  }
}
/*********************************************************************/

/********************************************************************* 
 * Data de criacao    : 04/09/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * INITSHEATPOL: inicializao a estrutura para o calculo dp calor     *
 * especifico em funcao da temperauta via polinomio                  *
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------* 
 *-------------------------------------------------------------------* 
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 * www.engineeringtoolbox.com/water-thermal-properties-d_162.html	   *
 *                                                                   *
 * regressao com polinomio de ordem 5 obtido pelo excel              *
 *                                                                   *
 *********************************************************************/
void initSheatPol(void) {

  sHeat.nPol = 6;

  sHeat.a[0] = 1.143178880938200E+00;
  sHeat.a[1] =-1.694359211627670E-03;
  sHeat.a[2] = 7.966237791866350E-06;
  sHeat.a[3] =-1.860841726408540E-08;
  sHeat.a[4] = 2.239058739944800E-11;
  sHeat.a[5] =-1.060989866966260E-14;

}
/*********************************************************************/

/********************************************************************* 
 * Data de criacao    : 06/09/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * GETTEMPFORENERGY: obtem a temperatura aprtir da entalpia sensivel *
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * temp   - nao definido                                             *
 * energy - entalpia sensivel                                        * 
 * prop   - propriedades por material                                *
 * mat    - material da celula                                       *
 * nCell  - numero da celulas                                        *
 * fTemp  - equaca da energia na forma de temperatura (true|false)   *
 * fsHeat - variacao do calor especifico em funcao da Temperatura    *
 *          (true|false)                                             *
 * fKelnvin - temperatura em kelvin (true|false)                     *
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------*
 * temp   - temperatura (C ou kelvin)                                * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void getTempForEnergy(DOUBLE *RESTRICT temp,DOUBLE *RESTRICT energy
                     ,DOUBLE *RESTRICT prop,short  *RESTRICT mat 
                     ,INT const nCell      ,bool const fTemp
                     ,bool const fSheat    ,bool const fKelvin){
  
  short lMat;
  INT i;  
  DOUBLE sHeat,t;

/*... resolucao da eq da energia na forma de temperatura*/ 
  if(fTemp)
    for (i = 0; i < nCell; i++)
      temp[i] = energy[i]; 
/*...................................................................*/ 

/*... resolucao da eq da energia na forma de entalpia sensivel*/  
  else
/*...*/
    if (fSheat) {
      for (i = 0; i < nCell; i++) 
        temp[i] = specificEnthalpyForTemp(energy[i],fKelvin);
    }
/*...................................................................*/ 

/*...*/
    else {
 /*...*/
      for (i = 0; i < nCell; i++){
        lMat  = mat[i] - 1;
        sHeat = MAT2D(lMat, SPECIFICHEATCAPACITYFLUID, prop, MAXPROP);
        t = ENTHALPY_FOR_TEMP(sHeat,energy[i],TREF);
        if(!fKelvin)
           temp[i] = KELVIN_FOR_CELSIUS(t);
      }
/*...................................................................*/ 
    }
/*...................................................................*/ 

}
/*********************************************************************/

/********************************************************************* 
 * Data de criacao    : 06/09/2017                                   *
 * Data de modificaco : 00/00/0000                                   *
 *-------------------------------------------------------------------*
 * GETENERGYFORTEMP: obtem a entalpia sensivel apartir da temp       *
 *-------------------------------------------------------------------* 
 * Parametros de entrada:                                            * 
 *-------------------------------------------------------------------* 
 * temp   - temp                                                     *
 * energy - nao definido                                             * 
 * prop   - propriedades por material                                *
 * mat    - material da celula                                       *
 * nCell  - numero da celulas                                        *
 * fTemp  - equaca da energia na forma de temperatura (true|false)   *
 * fsHeat - variacao do calor especifico em funcao da Temperatura    *
 *          (true|false)                                             *
 * fKelnvin - temperatura em kelvin (true|false)                     *
 *-------------------------------------------------------------------* 
 * Parametros de saida:                                              * 
 *-------------------------------------------------------------------*
 * energy - entalpia sensivel                                        * 
 *-------------------------------------------------------------------* 
 * OBS:                                                              *
 *-------------------------------------------------------------------*
 *********************************************************************/
void getEnergyForTemp(DOUBLE *RESTRICT temp,DOUBLE *RESTRICT energy
                     ,DOUBLE *RESTRICT prop,short  *RESTRICT mat 
                     ,INT const nCell     
                     ,bool const fSheat    ,bool const fKelvin) {
  short lMat;
  INT i;  
  DOUBLE sHeat,t;

/*...*/ 
  if(fSheat)
    for (i = 0; i < nCell; i++) 
      energy[i] = tempForSpecificEnthalpy(temp[i],fKelvin); 
/*...................................................................*/ 

/*...*/ 
  else
    for (i = 0; i < nCell; i++) {
/*...*/
      if(fKelvin)
        t = temp[i];  
      else
        t = CELSIUS_FOR_KELVIN(temp[i]);  
/*...................................................................*/ 

      lMat  = mat[i] - 1;
      sHeat = MAT2D(lMat, SPECIFICHEATCAPACITYFLUID, prop, MAXPROP);

      energy[i] = TEMP_FOR_ENTHALPY(sHeat,t,TREF); 
    }
/*...................................................................*/ 
}
/*********************************************************************/