
/*
 * Copyright 2020-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 
/**************************************
 * serviceRequestWfSecCmp.cpp
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/SMCodeGen/templates/stateMachineTmpls/state.cpp.tt>
 **************************************/


#include "actionTable.h"
#include "actionHandlers/actionHandlers.h"
#include "mmeSmDefs.h"
#include "utils/mmeStatesUtils.h"
#include "utils/mmeTimerTypes.h"

#include "mmeStates/serviceRequestWfSecCmp.h"	
#include "mmeStates/serviceRequestWfInitCtxtResp.h"

using namespace mme;
using namespace SM;

/******************************************************************************
* Constructor
******************************************************************************/
ServiceRequestWfSecCmp::ServiceRequestWfSecCmp():State(service_request_wf_sec_cmp, defaultStateGuardTimerDuration_c)
{
        stateEntryAction = &MmeStatesUtils::on_state_entry;
        stateExitAction = &MmeStatesUtils::on_state_exit;
        eventValidator = &MmeStatesUtils::validate_event;
}

/******************************************************************************
* Destructor
******************************************************************************/
ServiceRequestWfSecCmp::~ServiceRequestWfSecCmp()
{
}

/******************************************************************************
* creates and returns static instance
******************************************************************************/
ServiceRequestWfSecCmp* ServiceRequestWfSecCmp::Instance()
{
        static ServiceRequestWfSecCmp state;
        return &state;
}

/******************************************************************************
* initializes eventToActionsMap
******************************************************************************/
void ServiceRequestWfSecCmp::initialize()
{
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::process_sec_mode_resp);
                actionTable.addAction(&ActionHandlers::send_init_ctxt_req_to_ue_svc_req);
                actionTable.setNextState(ServiceRequestWfInitCtxtResp::Instance());
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(SEC_MODE_RESP_FROM_UE, actionTable));
        }
        {
                ActionTable actionTable;
                actionTable.addAction(&ActionHandlers::send_service_reject);
                actionTable.addAction(&ActionHandlers::send_s1_rel_cmd_to_ue);
                actionTable.addAction(&ActionHandlers::abort_service_req_procedure);
                eventToActionsMap.insert(pair<uint16_t, ActionTable>(ABORT_EVENT, actionTable));
        }
}
