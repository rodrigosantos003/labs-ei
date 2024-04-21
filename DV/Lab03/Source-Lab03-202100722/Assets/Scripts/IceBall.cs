using UnityEngine;

public class IceBall : MonoBehaviour
{
    [SerializeField] private ProjectileDetails projectileDetails;
    private Rigidbody2D _rb;

    // Start is called before the first frame update
    void Start()
    {
        _rb = GetComponent<Rigidbody2D>();
        _rb.velocity = new Vector2(0, projectileDetails.IceballSpeed);
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
            player.TakeDamage(projectileDetails.IceballDamage);
        }

        Destroy(gameObject);
    }
}
