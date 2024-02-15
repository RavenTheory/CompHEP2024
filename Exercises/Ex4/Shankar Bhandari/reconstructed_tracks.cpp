
#include<ostream>
#include <iostream>
#include <cmath>
using namespace std;


class reconstructedTracks
{
protected:
    /* data */
    // four momentum
    double p_0, p_1, p_2, p_3;
    //magnitude of 3-momentum
    double mag_p_3;
    //Transverse momentum
    double p_t;
    //polar angle
    double theta; 
    //pseudorapidity
    double eta;

public:
    reconstructedTracks(double p0, double p1, double p2, double p3);

    double transverse_momentum() const;
    double pseudorapidity() const;
    double polar_angle() const;
    //Incase there is a need to get the individual data elements (could make it as an array to be returned but this should work decently too)
    double getp0() const;
    double getp1() const;
    double getp2() const;
    double getp3() const;

    

};

/* These function are defined outside the class because originally I was going to 
compile the classes into a library and use them as libraries. But since this is a
fairly simple and short exercise to make calsses with inheritance that only need
a simple test program, I decided to just have them all in a single file to not
make it any more complicated than necessary.
*/

reconstructedTracks::reconstructedTracks(double p0, double p1, double p2, double p3)
{
    p_0 = p0 ;
    p_1 = p1 ;
    p_2 = p2 ;
    p_3 = p3 ;
    p_t = sqrt(pow(p_1, 2)  + pow(p_2, 2)  );
    mag_p_3 = sqrt(pow(p1,2) + pow(p2,2) + pow(p3,2));

    /*
    WE get theta using u * v = |u||v| cos(theta)
    With u = (p1, p2, p3),  v = (0, 0, p3) and |v| = abs(p3) and |u| = mag_p_3  
    This means that u*v= |v|^2
    */

    theta  = acos( abs(p3)/mag_p_3 );
    eta = -log(tan(theta/2));
}

double reconstructedTracks::transverse_momentum() const{
    return p_t;
}

double reconstructedTracks::pseudorapidity() const{
    return eta;
}

double reconstructedTracks::polar_angle() const{
    return theta;
}

double reconstructedTracks::getp0() const{
    return p_0;
}

double reconstructedTracks::getp1() const{
    return p_1;
}

double reconstructedTracks::getp2() const{
    return p_2;
}

double reconstructedTracks::getp3() const{
    return p_3;
}


class simulatedParticle : public reconstructedTracks
{
private:
    int parent_particle_ID;
    int particle_ID;
public:
    
    simulatedParticle(double p0, double p1, double p2, double p3, int pID, int ID) 
        : reconstructedTracks(p0, p1, p2, p3)
    {
        parent_particle_ID = pID;
        particle_ID = ID;
    }

    int parentID() const{
        return parent_particle_ID;
    }

    int particleID() const{
        return particle_ID;
    }


};



//Now to test the classes we have a test program in main:

int main(){

    reconstructedTracks track(20, 1, 3, 4);

    // Test that the reconstructedTracks class functions work:
    cout << "The pseudorapidity of the reconstructed track is " << track.pseudorapidity() << endl;
    cout << "The polar angle of the reconstructed track is " << track.polar_angle() << endl;

    simulatedParticle k(20, 1, 3, 4, 10, 3);

    cout << "The pseudorapidity of simulated particle is " << k.pseudorapidity() << endl;
    // This tests that the class can use function from inherited class

    cout << "The parent particle id of the simulated particle is " << k.parentID() << endl;
    cout << "The particle id of the simulated particle is " << k.particleID() << endl ;
    // This tests the function in the class itself

    cout << "The classes seem to work!" << endl ;

    return 0;
}



















