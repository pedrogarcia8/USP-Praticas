package br.usp.lista02.ex05;

import java.util.ArrayList;

public abstract class Personagem {
    private String _nome;
    private String _nomeVidaReal;
    private ArrayList<Superpoder> _poderes = new ArrayList<>();
    private int _vida;
    
    Personagem(String pNome, String pNomeVidaReal, Superpoder pSuperpoder, int pVida){
        _nome = pNome;
        _nomeVidaReal = pNomeVidaReal;
        _poderes.add(pSuperpoder);
        _vida = pVida;
    }
    
    //retorna o nome
    public String getNome(){
        return _nome;
    }
    
    //retorna o nome da vida real
    public String getNomeVidaReal(){
        return _nomeVidaReal;
    }
    
    //retorna a soma dos multiplicadores dos poderes do personagem
    public double getTotalPoder(){
        double soma = 0;
        
        for (Superpoder sp: _poderes){
            soma += sp.getMultiplicador();
        }
        
        return soma;
    }
    
    //configura o nome
    public void setNome(String pNome){
        _nome = pNome;
    }
    
    //configura o nome da vida real
    public void setNomeVidaReal(String pNomeVidaReal){
        _nomeVidaReal = pNomeVidaReal;
    }
    
    //retorna a quantidade de vida
    public int getVida(){
        return _vida;
    }
    
    //configura a quantidade de vida
    public void setVida(int pVida){
        _vida = pVida;
    }
    
    //retorna o objeto com o nome definido por pSuperpoder
    private Superpoder getSuperpoder(String pSuperpoder){    
        for (Superpoder sp: _poderes){
            if(sp.getNome().equals(pSuperpoder)){
                return sp;
            }
        }
        
        return null;
    }
    
    //adiciona um superpoder ao personagem
    public void addSuperpoder(Superpoder pSuperpoder){
        //se ele já não tiver esse superpoder
        if(!(_poderes.contains(pSuperpoder))){
            _poderes.add(pSuperpoder);
        }
        else{
            System.out.println(_nome + " já possui esse superpoder!");
        }
    }
    
    //retorna uma lista de obejtos (superpoderes) do personagem
    public ArrayList<Superpoder> getSuperpoderes(){
        return _poderes;
    }
    
    //calcula as chances de defesa
    private boolean defender(){
        return Math.random() >= 0.75;
    }
    
    //ataca o personagem definido por pPersonagem
    public void atacar(int pDano, Personagem pPersonagem, String pSuperpoder){
        //verifica se o personagem possui o superpoder desejado
        Superpoder sp = getSuperpoder(pSuperpoder);
        
        //se o personagem possui
        if(sp != null){
            //se acertar o golpe (50% de chance)
            if ((Math.random() % 2) >= 0.5){
                //se o personagem atacado não conseguir se defender
                if(!pPersonagem.defender()){
                    //o valor do dano é multiplicado pelo multiplicador do superpoder
                    pDano = (int)(pDano * sp.getMultiplicador());
                    pPersonagem.setVida(pPersonagem.getVida() - pDano);
                    
                    System.out.println(_nome + " acertou " + pPersonagem.getNome() + " com um dano de " + pDano + " usando " + sp.getNome());
                    
                    //configurar a vida para 0, caso a vida do personagem atacado fique negativa
                    //ou seja, o personagem atacado foi morto
                    if(pPersonagem.getVida() < 0){
                        pPersonagem.setVida(0);
                    }
                }
                //se o personagem atacado conseguir se defender
                else{
                    System.out.println(pPersonagem.getNome() + " se defendeu!");
                }
            }
            //se errar o golpe (50% de chance)
            else{
                System.out.println(_nome + " errou o ataque " + sp.getNome() + "!");
            }
        }
        //se o personagem não possui o superpoder
        else{
            System.out.println(_nome + " não possui o superpoder " + pSuperpoder + "!");
        }
    }
}
