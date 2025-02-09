#ifndef MOVER_NODE_H
#define MOVER_NODE_H

#include <memory>
#include "PCA9685.h"

void move(std::vector<std::unique_ptr<PCA9685>>& chips);

#endif // MOVER_NODE_H
