using System.Collections;
using UnityEngine;

public class PlayerHealthController : MonoBehaviour
{
    [SerializeField] private PlayerHealth playerHealth;
    private SpriteRenderer _spriteRenderer;

    public void TakeDamage(int damage)
    {
        playerHealth.Value -= damage;
    }

    public void ApplyLowHealth()
    {
        if (playerHealth.Value < playerHealth.LowValue)
        {
            //Intermitent red flash
            StartCoroutine(FlashRed());
        }
    }

    private IEnumerator FlashRed()
    {
        while (true)
        {
            _spriteRenderer.color = Color.red;
            yield return new WaitForSeconds(0.3f);
            _spriteRenderer.color = Color.white;
            yield return new WaitForSeconds(0.3f);
        }

    }
    // Start is called before the first frame update
    void Start()
    {
        _spriteRenderer = GetComponent<SpriteRenderer>();
        playerHealth.AddListener(ApplyLowHealth);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
