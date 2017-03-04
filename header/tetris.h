#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>

#include <future>

#include <time.h>
#include <unistd.h>

#include <termios.h>

#include <thread>
#include <mutex>
#include <chrono>

#define MAP_HIGH 20
#define MAP_WIDTH 15

#define DOWN  2
#define RIGHT 3
#define LEFT  4
#define UP    5
#define ANY_DIR 6

using namespace std;

typedef struct pattern_retention {
  vector< vector< char > > pattern;
  int x, y;
  int state;
  int select;
} PATTERN_RETENTION;


