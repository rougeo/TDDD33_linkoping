#ifndef CONNECTIONPOINT_H
#define CONNECTIONPOINT_H

class ConnectionPoint {
  public:
    ConnectionPoint();
    void setPotential(double value);
    double getPotential();
  private:
    double potential = 0;
};

#endif
