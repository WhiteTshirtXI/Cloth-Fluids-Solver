#ifndef SIMULATION_H
#define SIMULATION_H

#include <Eigen/Core>
#include <Eigen/Sparse>
#include <vector>
#include <set>
#include <QMutex>
#include "simparameters.h"
#include <QGLWidget>
#include "cloth.h"

class RigidBodyTemplate;
class RigidBodyInstance;

typedef Eigen::Triplet<double> Tr;

class SimParameters;

class Simulation
{
public:
    Simulation(const SimParameters &params);
    ~Simulation();

    void takeSimulationStep();
    void initializeGL();

    void renderFloor();
    void renderObjects();
    void clearScene();
    void accelerateBody(double vx, double vy, double vz, double wx, double wy, double wz);
    Eigen::VectorXd computeGravForce();
    Eigen::VectorXd computeClothForce();

private:
    void loadFloorTexture();
    void loadRigidBodies();

    const SimParameters &params_;
    QMutex renderLock_;

    double time_;
    GLuint floorTex_;

    RigidBodyTemplate * bodyTemplate_;
    RigidBodyInstance * bodyInstance_;
    Cloth *cloth_;
};

#endif // SIMULATION_H

