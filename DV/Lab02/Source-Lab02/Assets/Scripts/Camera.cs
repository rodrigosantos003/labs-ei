using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Camera : MonoBehaviour
{
    [SerializeField] private Transform target;
    [SerializeField] private Vector3 offset = new Vector3(0, 10, -10);

    // Update is called once per frame
    void Update()
    {
        if(target != null)
        {
            transform.position = target.position + offset;
        }
    }
}
