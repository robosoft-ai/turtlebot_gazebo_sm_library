// Copyright 2021 RobosoftAI Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/*****************************************************************************************************************
 *
 * 	 Authors: Pablo Inigo Blasco, Brett Aldrich
 *
 ******************************************************************************************************************/

#pragma once

#include <smacc2/smacc.hpp>
// #include <nav2z_client/client_behavior>

namespace sm_dance_bot_warehouse_3
{
using cl_nav2zclient::CbPureSpinning;

// STATE DECLARATION
struct StNavigateToWaypoint1 : smacc2::SmaccState<StNavigateToWaypoint1, MsDanceBotRunMode>
{
  using SmaccState::SmaccState;

  // TRANSITION TABLE
  typedef mpl::list<

    Transition<EvCbSuccess<CbNavigateGlobalPosition, OrNavigation>, StNavigateToWaypointsX, SUCCESS>,
    Transition<EvCbFailure<CbNavigateGlobalPosition, OrNavigation>, StNavigateToWaypointsX, ABORT>

    >reactions;

  // STATE FUNCTIONS
  static void staticConfigure()
  {

    // x: 0.0 #-2.0
    // y: 5.25 # 0.5
    configure_orthogonal<OrNavigation, CbNavigateGlobalPosition>(2.0,0.0, 90.0);
    configure_orthogonal<OrNavigation, CbResumeSlam>();
  }
};
}  // namespace sm_dance_bot_warehouse_3
