//**************************************************************************
// Práctica 2 
// Nombre : Álvaro Ruiz-Cabello Sánchez 
// DNI : 31882456V
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{

glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);

for(unsigned int i=0; i<caras.size(); i++){
  glColor3f(r,g,b);
  glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
  glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
  glVertex3fv((GLfloat *) &vertices[caras[i]._2]);

}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores()
{
  
/*
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
glBegin(GL_TRIANGLES);
for (i=0;i<colores.size();i++){
	glColor3f(colores[i].r,colores[i].g,colores[i].b);
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);

	}
glEnd();
*/
 int i;
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	glBegin(GL_TRIANGLES);
	for (i=0;i<caras.size();i++){
		glColor3f(colores[i].r,colores[i].g,colores[i].b);
		glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
		glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
		}
	glEnd();

}

//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
	}
}

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
// vertices

vertices.resize(8);
vertices[0].x=0;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[4].x=0;vertices[4].y=tam;vertices[4].z=tam;
vertices[5].x=tam;vertices[5].y=tam;vertices[5].z=tam;
vertices[6].x=tam;vertices[6].y=tam;vertices[6].z=0;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=0;
vertices[3].x=0;vertices[3].y=0;vertices[3].z=0;
vertices[7].x=0;vertices[7].y=tam;vertices[7].z=0;

// triangulos

caras.resize(12);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=4;caras[1]._1=1;caras[1]._2=5;
caras[2]._0=4;caras[2]._1=5;caras[2]._2=6;
caras[3]._0=6;caras[3]._1=5;caras[3]._2=1;
caras[4]._0=6;caras[4]._1=1;caras[4]._2=2;
caras[5]._0=2;caras[5]._1=1;caras[5]._2=0;
caras[6]._0=2;caras[6]._1=0;caras[6]._2=3;
caras[7]._0=3;caras[7]._1=0;caras[7]._2=4;
caras[8]._0=3;caras[8]._1=4;caras[8]._2=7;
caras[9]._0=7;caras[9]._1=4;caras[9]._2=6;
caras[10]._0=3;caras[10]._1=7;caras[10]._2=6;
caras[11]._0=3;caras[11]._1=6;caras[11]._2=2;



colores.resize(caras.size());
asignar_randomColor();

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

  colores.resize(caras.size());
  asignar_randomColor();
  //colores_cambio();

}


void _triangulos3D::asignar_randomColor( )
{
  int i;

  for (i=0; i<colores.size(); i++){
    colores[i].r = rand()%1000/1000.0;
    colores[i].g = rand()%1000/1000.0;
    colores[i].b = rand()%1000/1000.0;
  }
}

void _triangulos3D::colores_cambio(){
  int n_c;
  n_c=caras.size();
  colores.resize(n_c);

  for(int i = 0; i<n_c; i++){
    if(vertices[caras[i]._0].x>0.0){
      colores[i].r=0;
      colores[i].g=0;
      colores[i].b=0;
    }
    else{
      colores[i].r=123;
      colores[i].g=0.0;
      colores[i].b=254;
    }
  }
}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
   const char * n_file = "beethoven";
  vector<float> coordenadas;
  vector<int> triangulos;
  _file_ply::read(n_file, coordenadas, triangulos);

  int contador = 0;
  vertices.resize(coordenadas.size()/3);
  for(unsigned int i=0; i<coordenadas.size(); i+=3){
      vertices[contador].x = coordenadas[i];
      vertices[contador].y = coordenadas[i+1];
      vertices[contador].z = coordenadas[i+2];
      contador++;
      }
  contador = 0;
  caras.resize(triangulos.size()/3);
  for(unsigned int i=0; i<triangulos.size(); i+=3){
      caras[contador]._0 = triangulos[i];
      caras[contador]._1 = triangulos[i+1];
      caras[contador]._2 = triangulos[i+2];
      contador++;
      }

  colores.resize(caras.size());
  asignar_randomColor();
 
}



void _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car, i;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);

//escribir aqui vertices y caras 

/*
for (i=0;i<n_ver;i++){
  vertices[i].x=ver_ply[i*3];
  vertices[i].x=ver_ply[i*3+1];
  vertices[i].x=ver_ply[i*3+2];
}

for(i=0; i<n_car;i++){
  caras[i]._0=car_ply[i*3];
  caras[i]._1=car_ply[i*3+1];
  caras[i]._2=car_ply[i*3+2];
}*/
}


//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num,int tapa_in,int tapa_sup)
{
int i,j;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=perfil.size();
vertices.resize(num_aux*num+2); //El numero de vertices que vamos a tener es num_aux (puntos que tiene el perfil ) * numero (numero de veces que lo vamos a rotar) +2 (punto central de la tapa inferior y superior) 
for (j=0;j<num;j++){ 
    for (i=0;i<num_aux;i++) //Para cada uno de los puntos del perfil 
     {
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
     }
}



// tratamiento de las caras 

//Redimensiono el vector de caras
caras.resize(2*(num_aux-1)*num+2*num);  //

for (j=0; j<num-1; j++){ //El -1 es por que la ultima cara se procesa de manera independiente 
  for (i=0; i<num_aux-1; i++){ 
    cara_aux._0=i+j*num_aux;
    cara_aux._1=i+((j+1)%num)*num_aux;
    cara_aux._2=i+1+j*num_aux;
    caras.push_back(cara_aux);

    cara_aux._0=i+((j+1)%num)*num_aux;
    cara_aux._1=i+1+((j+1)%num)*num_aux;
    cara_aux._2=i+1+j*num_aux;
    caras.push_back(cara_aux);  
  }
}

//Procesamos la ultima cara 

int vert_ult_perf=j*num_aux;

for (int i=0;i< (num_aux-1);i++){
  cara_aux._0=i+vert_ult_perf;
  cara_aux._1=i+1;
  cara_aux._2=i;

  caras.push_back(cara_aux);

  cara_aux._0=i+vert_ult_perf;
  cara_aux._1=i+1+vert_ult_perf;
  cara_aux._2=i+1;

  caras.push_back(cara_aux);

}


     
// tapa inferior
if(tapa_in==1){

  //punto central de la tapa 
  vertice_aux.x=0.0;
  vertice_aux.y=perfil[0].y;
  vertice_aux.z=0.0;
  vertices.push_back(vertice_aux);

  //caras tapa inferior

  for(j=0; j<num;j++){
    cara_aux._0=vertices.size()-1; //vertices.size() es el punto central de la tapa superior 
    cara_aux._1=((j+1)%num)*num_aux;
    cara_aux._2=j*num_aux;
    caras.push_back(cara_aux);
  }

}
 
// tapa superior
if(tapa_sup==1){
  vertice_aux.x=0.0;
  vertice_aux.y=perfil[num_aux-1].y;
  vertice_aux.z=0.0;
  vertices.push_back(vertice_aux);

  /*if(tapa_in==1) cara_aux._0=vertices.size()-1;
  else cara_aux._0=vertices.size()-1;*/

  cara_aux._0=vertices.size()-1;

  for(j=0; j<num; j++){
    cara_aux._1=j*num_aux+num_aux-1;
    cara_aux._2=((j+1)%num)*num_aux+num_aux-1;
    caras.push_back(cara_aux);
  }
}

  colores.resize(caras.size());
  //asignar_randomColor();
  colores_cambio();
}

//************************************************************************
//objeto por revolución especiales
//************************************************************************
_cilindro::_cilindro(float radio,float altura,int lados){

  vector<_vertex3f> perfil;
  _vertex3f auxiliar;

  //almaceno en el vertice auxiliar el vertice inferior del perfil
  auxiliar.x=radio;
  auxiliar.y=-altura/2;
  auxiliar.z=0.0;   //No tiene valor en z ya que es solo el perfil

  //Aniado el vertice inferior del perfil al vector de vertices 
  perfil.push_back(auxiliar);

  //Ahora almaceno en el perfil auxiliar el vertice superior 
  auxiliar.x=radio;
  auxiliar.y=altura/2;
  auxiliar.z=0.0;

  //Aniado este vertice al perfil de vertices 
  perfil.push_back(auxiliar);


  parametros(perfil,lados,1,1);




}

_cono::_cono(float radio , float altura, int lados){

  vector<_vertex3f> perfil;
  _vertex3f auxiliar;

  //Vertice inferior del perfil 
  auxiliar.x=radio;
  auxiliar.y=-altura/2;
  auxiliar.z=0.0;

  //Almaceno el vertice que acabo de crear 
  perfil.push_back(auxiliar);

  //punta del cono 
  auxiliar.x=0.0;
  auxiliar.y=altura/2;
  auxiliar.z=0.0;

  //Almaceno el vertice de la punta del cono 
  perfil.push_back(auxiliar);

  parametros(perfil,lados,1,0);

}

_esfera::_esfera(float radio, int puntos , int lados ){

  vector<_vertex3f>perfil;
  _vertex3f auxiliar;

  //Calculo el resto de puntos del perfil de la esfera 
  for(int i=0;i<=puntos ;i++){ //i<=puntos ya que si no incluimos este "=" no pinta el vertice superior del perfil de la esfera 
    auxiliar.x = radio*cos(M_PI*i/puntos-M_PI/2.0);
    auxiliar.y = radio*sin(M_PI*i/puntos-M_PI/2.0);
    auxiliar.z = 0.0;

    //Almaceno el punto 
    perfil.push_back(auxiliar);
  }

  parametros(perfil,lados,0,0);


};

//Función para crear un objeto por revolución a partir de un fichero PLY

_ply_revolucion::_ply_revolucion(){
  // leer lista de coordenadas de vértices y lista de indices de vértices
   const char * n_file = "reina_ejedrez";
  vector<float> perfil;
  vector<int> triangulos;
  _file_ply::read(n_file, perfil, triangulos);

  int contador = 0;
  vertices.resize(perfil.size()/3);
  for(unsigned int i=0; i<perfil.size(); i+=3){
      vertices[contador].x = perfil[i];
      vertices[contador].y = perfil[i+1];
      vertices[contador].z = perfil[i+2];
      contador++;
      }
  /*contador = 0;
  caras.resize(triangulos.size()/3);
  for(unsigned int i=0; i<triangulos.size(); i+=3){
      caras[contador]._0 = triangulos[i];
      caras[contador]._1 = triangulos[i+1];
      caras[contador]._2 = triangulos[i+2];
      contador++;
      }*/

  parametros(vertices,15,1,1);

}

//************************************************************************
// objeto por extrusión
//************************************************************************


_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
int i;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=poligono.size();
vertices.resize(num_aux*2);
for (i=0;i<num_aux;i++)
    {
      vertices[2*i]=poligono[i];
      vertices[2*i+1].x=poligono[i].x+x;
      vertices[2*i+1].y=poligono[i].y+y;
      vertices[2*i+1].z=poligono[i].z+z;
    }
    
// tratamiento de las caras 

caras.resize(num_aux*2);
int c=0;
for (i=0;i<num_aux;i++)         
  {
   caras[c]._0=i*2;
   caras[c]._1=(i*2+2)%(num_aux*2);
   caras[c]._2=i*2+1;    
   c=c+1;
   caras[c]._0=(i*2+2)%(num_aux*2);
   caras[c]._1=(i*2+2)%(num_aux*2)+1;
   caras[c]._2=i*2+1;    
   c=c+1;    
      
   }  

    colores.resize(caras.size());
    asignar_randomColor();
 
}


