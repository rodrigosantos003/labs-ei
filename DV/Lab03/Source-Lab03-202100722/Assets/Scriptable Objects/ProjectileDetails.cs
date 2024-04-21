using UnityEngine;

[CreateAssetMenu(fileName = "ProjectileDetails", menuName = "Scriptable Objects/ProjectileDetails")]
public class ProjectileDetails : ScriptableObject
{
    [SerializeField] private int spikeDamage = 5;
    [SerializeField] private float spikeSpeed = 0.1f;

    [SerializeField] private int fireballDamage = 10;
    [SerializeField] private float fireballSpeed = 0.1f;

    [SerializeField] private int iceballDamage = 15;
    [SerializeField] private float iceballSpeed = 0.1f;


    public int SpikeDamage => spikeDamage;
    public float SpikeSpeed => spikeSpeed;
    public int FireballDamage => fireballDamage;
    public float FireballSpeed => fireballSpeed;
    public int IceballDamage => iceballDamage;
    public float IceballSpeed => iceballSpeed;
}
