using UnityEngine;

public class PlayerController : MonoBehaviour
{
    private Rigidbody2D _rb;
    private bool _jumpCommand;
    [SerializeField] private float jumpPower = 2.0f;

    private bool _leftCommand;
    private bool _rightCommand;
    [SerializeField] private float runSpeed = 2.0f;

    private bool _isGrounded;
    [SerializeField] private GameObject groundTestLineStart;
    [SerializeField] private GameObject groundTestLineEnd;

    [SerializeField] private float timeLimit;
    private float _timer;
    [SerializeField] private int objectsToCollect;
    private int _collectedObjects;

    [SerializeField] private GameText _gameText;

    public void CollectObject()
    {
        _collectedObjects++;
    }


    public int CollectedObjects => _collectedObjects;
    public float Timer => _timer;
    public int ObjectsToCollect => objectsToCollect;


    // Start is called before the first frame update
    void Start()
    {
        _rb = GetComponent<Rigidbody2D>();
        _timer = timeLimit;
    }

    // Update is called once per frame
    void Update()
    {
        _isGrounded = Physics2D.Linecast(groundTestLineEnd.transform.position, groundTestLineStart.transform.position);

        if (Input.GetKeyDown(KeyCode.Space) && _isGrounded)
        {
            _jumpCommand = true;
        }

        if (Input.GetKey(KeyCode.A))
        {
            _leftCommand = true;
            Vector2 scale = transform.localScale;
            scale.x = -5;
            transform.localScale = scale;
        }

        if (Input.GetKey(KeyCode.D))
        {
            _rightCommand = true;
            Vector2 scale = transform.localScale;
            scale.x = 5;
            transform.localScale = scale;
        }

        _timer -= Time.deltaTime;
        _gameText.UpdateText();
       
    }

    void FixedUpdate()
    {
        if (_jumpCommand && _isGrounded)
        {
            _rb.velocity = new Vector2(_rb.velocity.x, jumpPower);  
            _jumpCommand = false;
        }

        if(_leftCommand)
        {
            _rb.velocity = new Vector2(-runSpeed, _rb.velocity.y);
            _leftCommand = false;
        }

        if(_rightCommand)
        {
            _rb.velocity = new Vector2(runSpeed, _rb.velocity.y);
            _rightCommand = false;
        }
    }
}
