#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>

#include <time.h>
#include <unistd.h>

using namespace std;

typedef struct pattern_retention {
  vector< vector< char > > pattern;
  int x, y;
} PATTERN_RETENTION;

