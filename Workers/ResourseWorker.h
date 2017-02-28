#ifndef WORKERS_RESOURSEWORKER_H_
#define WORKERS_RESOURSEWORKER_H_
#include "WorldWorker.h"

class ResourseWorker: public WorldWorker {
public:
	ResourseWorker();
	virtual ~ResourseWorker();
    void work(World *world) override;
    double gainResourse =5.0;
	void setRandomXY(World* world);
    int rand_y;
    int rand_x;

};

#endif /* WORKERS_RESOURSEWORKER_H_ */
