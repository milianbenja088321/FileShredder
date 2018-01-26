using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;
namespace Vuforia
{
    public class ARVRManagerScript : MonoBehaviour
    {
        private void Awake()
        {
            VuforiaRuntime.Instance.Deinit();
           
            if (GetComponent<VuforiaBehaviour>().enabled)
            {
                GetComponent<VuforiaBehaviour>().enabled = false;
                GetComponent<DefaultInitializationErrorHandler>().enabled = false;
            }
        }

    }
}
