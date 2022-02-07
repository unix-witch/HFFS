#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct GraphData {
    int error;
    int graphLen;
    double **points;

    char* graphDataFile;
    char* graphDataSect;

    void (*initGraphData)(struct GraphData *, char* file, char* sect);
    void (*readGraphData)(struct GraphData *);
    void (*freeGraphData)(struct GraphData *);
};

void readGraphData(struct GraphData *data) {
    FILE *fp = fopen(data->graphDataFile);





    fclose(fp);
}




void freeGraphData(struct GraphData *data) {
    for (int i=0; i < data->graphLen; i++)
        free(data->points[i]);
}

void initGraphData(struct GraphData* data, char* file, char* sect) {
    data->error = 0;
    data->graphLen = 0;
    data->graphDataFile = (char*)malloc(strlen(file)); //Allocate data file name
    data->graphDataSect = (char*)malloc(strlen(sect)); //Allocate data file section


    data->readGraphData = readGraphData;
    data->freeGraphData = freeGraphData;

    data->readGraphData(data);
}

#endif