using UnityEngine;

public class FireBall : MonoBehaviour
{
    [SerializeField] private ProjectileDetails projectileDetails;
    private Rigidbody2D _rb;

    // Start is called before the first frame update
    void Start()
    {
        _rb = GetComponent<Rigidbody2D>();
        _rb.velocity = Vector2.up * projectileDetails.FireballSpeed;
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
            player.TakeDamage(projectileDetails.FireballDamage);
        }

        Destroy(gameObject);
    }
}
