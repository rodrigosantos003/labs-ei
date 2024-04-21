using UnityEngine;

public class Spikes : MonoBehaviour
{
    [SerializeField] private ProjectileDetails projectileDetails;
    private Rigidbody2D _rb;
    

    // Start is called before the first frame update
    void Start()
    {
        gameObject.transform.rotation = Quaternion.Euler(transform.eulerAngles.x, transform.eulerAngles.y, 180f);
        _rb = GetComponent<Rigidbody2D>();
        _rb.velocity = new Vector2(0, projectileDetails.SpikeSpeed);
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.CompareTag("Player"))
        {
            PlayerHealthController player = collision.gameObject.GetComponent<PlayerHealthController>();
            player.TakeDamage(projectileDetails.SpikeDamage);
        }

        Destroy(gameObject);
    }
}
