
#include<iostream>
#include<iomanip>
#include<math.h>

using namespace std;


class Area
{
    private:
       int length;
       int breadth;
       int radius;
    public:
       
       friend long int areaOfRectangle(Area, int , int);
       friend double areaOfCircle(Area, int);

};


inline long int areaOfRectangle(Area a, int l =1, int b =1)
{
    a.breadth = b;
    a.length = l;

    return (a.length * a.breadth);
}

inline double areaOfCircle(Area a, int r =1)
{
   a.radius = r;
   long int sq = pow(a.radius,2);
   return (3.14 * sq);
}


class Volume
{
    private:
       int length, breadth, height;
       int radius;

    public:
    
       inline long int volumeOfCuboid(int length = 1, int breadth = 1, int heigth = 1)
       {
           this->length = length;
           this->breadth = breadth;
           this->height = heigth;
           Area a;

           return ( areaOfRectangle(a,this->length,this->breadth) * this->height);
       }
       
       inline long double volumeOfSphere(int radius = 1)
       {
          this->radius = radius;
          Area a;
          long double result = areaOfCircle(a,this->radius) * float(4)/3 * this->radius;
          return result;
       }

       
       void compareCubiod(long int volc1, long int volc2)
       {
           
           if(volc1 > volc2)
           {
               cout << "The volume of cuboid v1 > cubiod v2 " << endl;
           }
           else if(volc1  <  volc2)
           {
               cout << "The volume of cuboid v1 < cuboid v2" << endl;
           }
           else
           {
               cout << "Both volumes of cuboids are same " << endl;
           }
       }

      
       void compareSphere(long double vols1, long double vols2)
       {
           
           if(vols1 > vols2)
           {
               cout << "The volume of Sphere v1 > Sphere v2 " << endl;
           }
           else if(vols1  <  vols2)
           {
               cout << "The volume of Sphere v1 < Sphere v2" << endl;
           }
           else
           {
               cout << "Both volumes of spheres are same " << endl;
           }
       }
};

int main()
{ 
    Area a1;
    Volume v,v1,v2;
    int choice;
    int choice1;
    int length,breadth,heigth,radius;
    long int volc1,volc2;
    long double vols1,vols2;
    cout << endl;
   
    while(1)
    {
       cout << "Read Menu" << endl;
       cout << "1.Area of Rectangle \n2.Area of Circle \n3.Volume of Cuboid \n4.Volume of Sphere \n5.Compare volume of Two cuboid \n6.Compare Volume of Two Sphere \n7.EXIT" << endl;
       cout << "Enter Your Choice: ";
       cin >> choice;
       cout << endl;
       switch(choice)
       {
           case 1:
               cout << "1.For Default Area \n2.For User Input Area:" << endl;
               cout << "Choose your choice: ";
               cin >> choice1;
               if(choice1 == 1)
               {
                  cout << "The Area of Rectangle is: " << areaOfRectangle(a1) << " sq units" << endl;
               }
               else if(choice1 == 2)
               {
                   cout << "Enter the length: ";
                   cin >> length;
                   cout << "Enter the Breadth: ";
                   cin >> breadth;
                   cout << "The Area of Rectangle is: " << areaOfRectangle(a1,length,breadth) << " sq units" << endl;
               }
               else
               {
                    cout << "Invalid Choice" << endl;
               }
               cout << endl;
               break;
            case 2:
               cout << "1.For Default Area of Circle \n2.For User Input Area:" << endl;
               cout << "Choose your choice: ";
               cin >> choice1;
               if(choice1 == 1)
               {
                  cout << "The Area of Circle is: " << fixed << setprecision(2)<< areaOfCircle(a1) - 2.14 << " sq units" << endl;
               }
               else if(choice1 == 2)
               {
                   cout << "Enter the radius: ";
                   cin >> radius;
                   cout << "The Area of Circle is: " <<  fixed << setprecision(2) << areaOfCircle(a1,radius) << " sq units" << endl;
               }
               else
               {
                    cout << "Invalid Choice" << endl;
               }
               cout << endl;
               break;
            case 3:
               cout << "1.For Default Volume \n2.For User Input Volume:" << endl;
               cout << "Choose your choice: ";
               cin >> choice1;
               if(choice1 == 1)
               {
                  cout << "The Volume of Cuboid is: " << v.volumeOfCuboid() << " cube units"<< endl;
               }
               else if(choice1 == 2)
               {
                   cout << "Enter the length: ";
                   cin >> length;
                   cout << "Enter the Breadth: ";
                   cin >> breadth;
                   cout << "Enter the Heigth: ";
                   cin >> heigth;
                   cout << "The Volume of Cuboid is: " << v.volumeOfCuboid(length,breadth,heigth) << " cube units"<< endl;
               }
               else
               {
                    cout << "Invalid Choice" << endl;
               }
               cout << endl;
               break;
            case 4:
               cout << "1.For Default Volume \n2.For User Input Volume:" << endl;
               cout << "Choose your choice: ";
               cin >> choice1;
               if(choice1 == 1)
               {
                  cout << "The Volume of Sphere is: " << fixed << setprecision(1) <<v.volumeOfSphere() - 3.17 << " cube units"<< endl;
               }
               else if(choice1 == 2)
               {
                   cout << "Enter the radius: ";
                   cin >> radius;
                   cout << "The Volume of Sphere is: " << fixed << setprecision(2)<< v.volumeOfSphere(radius) << " cube units"<< endl;
               }
               else
               {
                    cout << "Invalid Choice" << endl;
               }
               cout << endl;
               break;
            case 5:
               cout << "Enter details of two cubois: \n"<< endl;
               cout << "Enter details of 1 cuboid :\n " << endl;
               cout << "Enter length: ";
               cin >> length;
               cout << "Enter breadth: ";
               cin >> breadth;
               cout << "Enter heigth: ";
               cin >> heigth;
               volc1 = v.volumeOfCuboid(length,breadth,heigth);

               cout << "Enter details of 2 cuboid :\n " << endl;
               cout << "Enter length: ";
               cin >> length;
               cout << "Enter breadth: ";
               cin >> breadth;
               cout << "Enter heigth: ";
               cin >> heigth;
               cout << endl;
               volc2 = v.volumeOfCuboid(length,breadth,heigth);
               v.compareCubiod(volc1,volc2);
                break;
            case 6:
               cout << "Enter details of two sphere: \n"<< endl;
               cout << "Enter details of 1 sphere:\n " << endl;
               cout << "Enter radius: ";
               cin >> radius;
               vols1 = v.volumeOfSphere(radius);

               cout << "Enter details of 2 sphere :\n " << endl;
               cout << "Enter radius: ";
               cin >> radius;
               cout << endl;
               vols2 = v.volumeOfSphere(radius);
               v.compareSphere(vols1,vols2);

               break;
            case 7:
               exit(0);
            default :
               cout << "Invalid! Enter a correct Choice " << endl;
               cout << endl;
               break;
       } 
    }
    return 0;
}
