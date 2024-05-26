using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Spawner : MonoBehaviour
{
    private BoxCollider _floor;
    [SerializeField] private GameObject itemPrefab;
    [SerializeField] private Transform playerTransform;

    // Start is called before the first frame update
    void Start()
    {
        _floor = GetComponent<BoxCollider>();
    }

    // Update is called once per frame
    void Update()
    {
    }

    public void SpawnItem()
    {
        float min = _floor.bounds.min.x + 5;
        float max = _floor.bounds.max.x - 5;

        Vector3 spawnArea = new Vector3(Random.Range(min, max), 1, Random.Range(min, max));
        GameObject item = Instantiate(itemPrefab, spawnArea, Quaternion.identity);
        ObjectController objectController = item.GetComponent<ObjectController>();
        objectController.PlayerTransform = playerTransform;
    }
}
