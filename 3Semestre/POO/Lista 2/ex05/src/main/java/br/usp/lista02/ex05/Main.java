package br.usp.lista02.ex05;

public class Main {    
    public static void main(String[] args){
        Superpoder sp1 = new Superpoder(0, "Porrada", (Math.random()+1));
        Superpoder sp2 = new Superpoder(0, "Voadora", (Math.random()+1));
        Superpoder sp3 = new Superpoder(0, "Rasteira", (Math.random()+1));
        
        SuperHeroi sh = new SuperHeroi("Homem Cueca", "Roberto", sp1, 150);
        sh.addSuperpoder(sp3);
        
        Vilao v = new Vilao("Coringa", "Márcio", sp2, 100, 20);
        
        //enquanto ambos estiverem vivos
        while((sh.getVida() > 0) && (v.getVida() > 0)){
            //mostra a quantidade de vida restante dos personagens
            System.out.println("Vida de " + sh.getNome() + ": " + sh.getVida());
            System.out.println("Vida de " + v.getNome() + ": " + v.getVida());
            
            //define a vez de quem ataca
            if(Math.random() >= 0.5){
                //define qual superpoder sh irá usar (50% de chance)
                if(Math.random() >= 0.5){
                    sh.atacar(((int)(Math.random()*100)), v, "Porrada");
                }
                else{
                    sh.atacar(((int)(Math.random()*100)), v, "Rasteira");
                }
            }
            else{
                v.atacar(((int)(Math.random()*100)), sh, "Voadora");
            }
            
            System.out.println("");
        }
        
        if(sh.getVida() == 0){;
            System.out.println(sh.getNome() + " morreu!");
            System.out.println(v.getNome() + " ganhou!");
        }
        else{
            System.out.println(v.getNome() + " morreu!");
            System.out.println(sh.getNome() + " ganhou!");
        }
    }
}
