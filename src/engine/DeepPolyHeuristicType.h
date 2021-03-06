/*********************                                                        */
/*! \file DeepPolyHeuristicType.h
** \verbatim
** Top contributors (to current version):
**   Haoze Andrew Wu
** This file is part of the Marabou project.
** Copyright (c) 2017-2019 by the authors listed in the file AUTHORS
** in the top-level source directory) and their institutional affiliations.
** All rights reserved. See the file COPYING in the top-level source
** directory for licensing information.\endverbatim
**
** [[ Add lengthier description here ]]

**/

#ifndef __DeepPolyHeuristicType_h__
#define __DeepPolyHeuristicType_h__

/*
  MILP solver bound tighening options
*/
enum class DeepPolyHeuristicType
{
     DEFAULT = 0,
     RANDOM = 1,
     NOTHING = 2,
};

#endif // __DeepPolyHeuristicType_h__
