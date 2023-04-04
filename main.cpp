#include "PIFilter.h"
#include "PIDefines.h"
#include "PIActions.h"
#include "PIUSuites.h"

DLLExport MACPASCAL void PluginMain(const int16 selector,
                                    FilterRecordPtr filterRecord,
                                    intptr_t *data,
                                    int16 *result) {
  if (selector == filterSelectorAbout) {
    // Handle displaying the About dialog for your plugin.
  } else if (selector == filterSelectorParameters) {
    // Handle getting or setting plugin parameters if needed.
  } else if (selector == filterSelectorPrepare) {
    *result = noErr;
  } else if (selector == filterSelectorStart) {
    // Fill the current selection with the foreground color.
    if (filterRecord->sSPBasic) {
      PSActionDescriptorProcs *descriptorProcs = NULL;
      PSActionControlProcs *actionControlProcs = NULL;
      
        sPSActionDescriptor = ((PSActionDescriptorProcs*)filterRecord->handleProcs->handle[0]);
        sPSActionControl = ((PSActionControlProcs*)filterRecord->handleProcs->handle[1]);


      if (descriptorProcs && actionControlProcs) {
        // Create an action reference targeting the current selection.
        PIActionReference selectionRef;
        descriptorProcs->Make(selectionRef, &selectionRef);
        descriptorProcs->PutClass(selectionRef, cSelection);

        // Create an action descriptor containing the foreground color as the fill color.
        PIActionDescriptor fillDesc;
        descriptorProcs->Make(&fillDesc);
        descriptorProcs->PutEnumerated(fillDesc, keyUsing, typeFillContents, enumForegroundColor);

        // Fill the selection with the foreground color.
        actionControlProcs->Play(eventFill, fillDesc, plugInDialogSilent);

        // Deselect the current selection.
        actionControlProcs->Play(eventDeselect, NULL, plugInDialogSilent);

        // Release resources.
        // No need to release resources in this case, as they're managed by the Photoshop SDK.

      }
    }

    *result = noErr;
  } else if (selector == filterSelectorContinue) {
    *result = noErr;
  } else if (selector == filterSelectorFinish) {
    *result = noErr;
  } else {
    *result = filterBadParameters;
  }
}
