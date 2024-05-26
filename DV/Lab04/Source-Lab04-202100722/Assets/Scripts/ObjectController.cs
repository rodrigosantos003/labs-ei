using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;

public class ObjectController : MonoBehaviour
{
    [SerializeField] private AudioClip itemSound;
    [SerializeField] private AudioClip itemPickupSound;
    [SerializeField] private float maxDistance = 10f;

    private Transform _playerTransform;
    private AudioSource _audioSource;

    public Transform PlayerTransform
    {
        get => _playerTransform;
        set => _playerTransform = value;
    }

    // Start is called before the first frame update
    void Start()
    {
        _audioSource = GetComponent<AudioSource>();
        _audioSource.loop = true;
        _audioSource.Play();
    }

    // Update is called once per frame
    void Update()
    {
        if (_playerTransform == null)
            return;

        float distanceToPlayer = Vector3.Distance(transform.position, _playerTransform.position);
        float volume = Mathf.Clamp01(1f - (distanceToPlayer / maxDistance));
        _audioSource.volume = volume;
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            PlayerController playerController = other.gameObject.GetComponent<PlayerController>();
            playerController.CollectItem();
            StartCoroutine(PlayAndDestroy());
        }
    }

    private IEnumerator PlayAndDestroy()
    {
        // Pausa a execução até que o som termine de tocar
        _audioSource.Stop();
        _audioSource.PlayOneShot(itemPickupSound, 1f);
        yield return new WaitForSeconds(itemPickupSound.length-1f);

        // Destruir o objeto após o som terminar de tocar
        Destroy(gameObject);

        Spawner spawner = GameObject.Find("Floor").GetComponent<Spawner>();
        spawner.SpawnItem();
    }
}
