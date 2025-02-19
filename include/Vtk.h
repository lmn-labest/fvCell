#ifndef _VTK_
  #define _VTK_
  #define INTEGER_VTK 1
  #define DOUBLE_VTK  2
  #define SCALARS_VTK 1
  #define VECTORS_VTK 2
  #define TENSORS_VTK 3

/*... vtk elmentos*/
  #define VTK_DOT       1
  #define VTK_LINE      3
  #define VTK_TRIA      5
  #define VTK_QUAD      9
  #define VTK_TETR     10
  #define VTK_HEXA     12
  #define VTK_PIRA     14
/*...................................................................*/

  #include<stdio.h>
  #include<stdlib.h>
  #include<HccaStdBool.h>
  #include<Mesh.h>
  void headVtk(char *,bool, FILE *);
  void writeVtkCoor(double *x,INT nnode   ,int ndm,bool cod, FILE *f);
  void writeVtkCell(int *el   ,short *nen ,short *type
                   ,INT numel ,short maxno,bool cod
                   ,FILE *f);
  void writeVtkProp(int *iprop,double *dprop,INT  n
                   ,int gdl   ,char *s     ,bool cod1
                   ,short cod2,short cod3  ,FILE *f);
  void writeVtkNodeProp(int *iprop,double *dprop,short cod1,short cod2
                       ,int nnode ,short ndf    ,char *s   ,bool cod
                       ,FILE *f);

  void timeVtk(double t,int iStep,bool cod,FILE *f);
  void timeVtk2(double t,bool cod,FILE *f);

#endif /*_VTK_*/
