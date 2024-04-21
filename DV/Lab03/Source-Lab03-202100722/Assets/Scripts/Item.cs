using UnityEngine;

public class Item : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        // If the player collides with the item
        if (collision.gameObject.CompareTag("Player"))
        {
            //Update the player's collected objects
            collision.gameObject.GetComponent<PlayerController>().CollectObject();

            // Destroy the item
            Destroy(gameObject);
        }
    }
}
