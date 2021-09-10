package br.usp.lista02.ex05;

public class Vilao extends Personagem{
    private int _anosDePrisao;
    
    Vilao(String pNome, String pNomeVidaReal, Superpoder pSuperpoder, int pVida, int pAnosDePrisao){
        super(pNome, pNomeVidaReal, pSuperpoder, pVida);
        _anosDePrisao = pAnosDePrisao;
    }
    
    //retorna o número de anos na prisão
    public int getAnosDePrisao(){
        return _anosDePrisao;
    }
    
    //configura o número de anos na prisão
    public void setAnosDePrisao(int pAnosDePrisao){
        _anosDePrisao = pAnosDePrisao;
    }
}
