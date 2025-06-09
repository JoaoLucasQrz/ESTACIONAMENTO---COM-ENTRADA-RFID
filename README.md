ESTACIONAMENTO---COM-ENTRADA-RFID 

** INTRODUÇÃO **

O crescimento acelerado das áreas urbanas e o consequente aumento na frota de veículos, a demanda por soluções eficientes e automatizadas para gerenciamento de vagas de estacionamento tornou-se uma necessidade urgente. Estacionamentos convencionais muitas vezes apresentam falhas como uso ineficiente do espaço, dificuldades de localização de vagas disponíveis, falta de controle de acesso e segurança limitada. Este projeto propõe a criação de um estacionamento inteligente baseado em Arduino, utilizando sensores ultrassônicos para detecção da presença de veículos nas vagas, leitores RFID para identificação e controle de acesso de usuários autorizados, LEDs para sinalização de disponibilidade das vagas, display LCD para informações em tempo real, e motores microservo para abertura/fechamento automatizado de cancelas. A integração desses componentes possibilita um sistema automatizado, de fácil instalação e com grande aplicabilidade em ambientes residenciais, comerciais ou institucionais. Além de proporcionar um melhor aproveitamento do espaço e reduzir o tempo de busca por uma vaga, o projeto contribui para o aprimoramento da segurança e do controle de acesso ao estacionamento​

** METODOLOGIA **

Início do Projeto ​

→ Todos os membros (João Lucas, João Vitor, Nicolas Barros, Isaque Lopes)​

Pesquisa de Componentes e Requisitos ​→ João Lucas, João Vitor​
Montagem do Protótipo (estrutura física, sensores, fiação) ​→ Nicolas Barros, Isaque Lopes, João Vitor​
Programação e Testes dos Módulos (RFID, ultrassônicos, servos, LEDs, LCD) ​→ João Lucas, Nicolas Barros, Isaque Lopes​
Integração dos Componentes e Ajustes Finais ​→ João Lucas, João Vitor​
Apresentação e Documentação do Projeto ​→ Todos os membros (João Lucas, João Vitor, Nicolas Barros, Isaque Lopes)​
** RESULTADOS ** O protótipo demonstrou um funcionamento eficiente, identificando corretamente veículos autorizados por meio do leitor RFID e liberando o acesso com acionamento do motor microservo, simulando a abertura da cancela. O sistema também identificou com precisão a presença ou ausência de veículos nas vagas, utilizando sensores ultrassônicos.​

OBSERVAÇÕES - DIFICULDADES E APRENDIZADOS Durante o desenvolvimento, a equipe enfrentou desafios na calibração dos sensores ultrassônicos e na sincronização entre os módulos RFID e os servos. A superação dessas dificuldades contribuiu significativamente para o aprendizado em eletrônica, lógica de programação e integração de hardware.​

> COMPONENTES USADOS

Sensores Ultrassônicos​
Leitores RFID​
Motores Microservo​
Display LCD 16x2​
Protoboards ​
Placa Arduino Uno ​
Leds 4mm Vermelhos​
Leds 4mm Verdes​
>TESTES REALIZADOS

15 testes de leitura RFID​
15 testes de detecção de vaga​
10 testes completos com fluxo de entrada e saída​
Taxa de sucesso:​

100% de leituras RFID corretas com tags cadastradas​
90% de precisão na detecção de veículos pelos sensores​
95% de funcionamento correto do sistema integrado (completa leitura + abertura + indicação de vaga)​​
