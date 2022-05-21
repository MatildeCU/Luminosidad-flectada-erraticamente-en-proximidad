# Documentación de un proyecto del Taller de Interacción

En este repositorio encontraras el desarrollo del uno de los proyectos del Taller de Diseño de Interacción del año 2022, de la Escuela de Arquitectura y Diseño. Desarrollado por las alumnas Valentina Dietz, Matilde Croxatto Ullrich y el alumno Andrés Aliaga Chandía. Aquí ordenamos la documentación de este proyecto para su exposición y posible re edicción ya que disponemos los archivos de corte para láser, códigos de arduino y otras informaciones necesarias.

## Observaciones de referencia

![Esta es una imagen](https://github.com/MatildeCU/Luminosidad-flectada-erraticamente-en-proximidad/blob/main/Ima/Totem%20M%C3%B3dulo%202%20Taller%20de%20Dise%C3%B1o%20de%20Interacci%C3%B3n%20Dibujo%20iso%20v1-01.jpg)

- Aproximación versátil desde el vacío expansivo al volumen próximo 
- Rodear sostenido del vacío 
- Apertura y recogimiento articulado en continuidad

## Acercamiento a la forma

Se conversó como grupo sobre las diversas observaciones y encuentros que tuvimos, llegando a una observación por cada uno, que guiará la propuesta final del totem. Se determinó el concepto de proximidad como uno de estos, por lo cual unos de los inputs del Tótem es un sensor de ultra sonido el cual mide la distancia de un objeto enviando y recibiendo señales sonoras. La segunda característica observada es lo errático, aquello es expresado el en el movimiento de dentro del Tótem, el cual se efectuará mediante un motor activado por los sensores ultrasónicos. Este movimiento será expresado por una tela al interior del objeto. Luz Flectada es aquello que se logró en la unión se estos conceptos.

Además se presentarán dos output con máximos y mínimos, la intensidad de las luces manejadas con botones ubicados en los laterales del Tótem y la altura en desplazamiento de estas. Esto ya que se dispondrán ocho botones en total, cada cara contará con dos, los cuales se podrán activar en pares o individualmente. Cara placa con los botones estará en distintas alturas, así se tendrá que disponer el cuerpo a estirarse o a recogerse para activarlos.

### A escala menor
Partimos probando cilindros de tela que se van recogiendo mientras se proyecta la textura de estos mismos en contraluz. La luz central se va controlando manualmente en búsqueda de pruebas; subir y bajar, acercarse y alejarse, etc. A partir de estas pruebas van apareciendo distintas proyecciones en el espacio, de las cuales podemos rescatar algunas más interesantes que otras. La luz se hace parte relevante en la proyección cuando ambas telas se superponen en movimiento y la fuente luminica se va acercando a la "arruga".

![Esta es una imagen](Construccion_escala_menor_totem_MVA_pruebas_constructivas_(2).jpg)
![Esta es una imagen]()
![Esta es una imagen]()

## Proceso constructivo

Comenzamos realizando las pruebas a escala 1:1. en donde pudimos replicar de cierta manera lo descubierto en el movimiento de las telas, pero esta vez a través de hilos. En donde los hilos integrados a la tela arrugan esta misma para ir formando distintas texturas dentro del espacio en contraluz. Una vez definidos, a que el gesto se expresaría en la proyección de la sombra de estas telas arrugadas, se dio paso a la construcción del mecanismo que produciría este movimiento. 
Se decidió instalar un motor en la parte superior del totem, en el que se montó un servo. Así a modo de pulsador (muy parecido al movimiento qure hace un dedo al presionar) este mecanismo presiona nueve hilos por cara, que están vinculados a la tela. Este mecanismo, es accionado a través de sensores de proximidad; es decir, que cuando el usuario se ubica en la cara uno, el motor modificará exclusivamente esa cara.

Por otra parte se trabajó en uyn aparato lumínico, que recorre en totem en un eje vertical central. este aparato es el encargado de proyectar la luz que se ensombrece con las telas. Este aparato es accionado a traves de cuatro botones, ubicados uno en cada cara, los cuales modifican: intensidad, ritmos o bucles programados. 
Finalmente se instaló una membrana translúcida levemente opaca (papel diamante) en la que se proyectan posteriormente estas luces flectadas. 



- La luz
Se busca una propuesta azaroza del color, para lo que se utiliza la función random de arduino, configurados los LEDs de la forma analogWrite(R, random (150,250)); analogWrite(G,random(150,250));analogWrite(B,random (150,250)).
![Esta es una imagen](500px-Luz_flectada_MVA.png)
![Esta es una imagen](500px-Luz_flectada_mva_2.png)
![Esta es una imagen](600px-Luz_totem_MVA_(1).jpg)
![Esta es una imagen](600px-Luz_totem_MVA_(12.png)
![Esta es una imagen](600px-Luz_totem_MVA_(2).jpg)
![Esta es una imagen](600px-Luz_totem_MVA_(3).jpg)

- Tela
Se utilizó tela de velo liso por su capacidad de maleabilidad sombreada. Es decir que en la suma de arrugas generó sombras expresivas. 
![Esta es una imagen](500px-Pruebas_tela_escala_real_mva_(2).png)
![Esta es una imagen](Hilos_tela_mva_2.png)

- Hilos
En la propuesta se utilizó hilo de pescar de 0.05 mm, por su resistencia a la tracción y poco roce.
![Esta es una imagen](600px-Hilos_tela_mva.jpg)
![Esta es una imagen]()


- Mecanismos
 Mecanismo sperior:
 Se utiliza un motor de tipo stepper (paso a paso) y un servo. El motor posicionará al servo en la cara e hilos correspondientes, mientras que el servo montado en el será el encargado de presionar dichos hilos.
 Mecanismo sube y baja del aparato lumínico:
 Se instaló un motor stepper (paso a paso) en la parte inferior del totem, este, a través de una correa que recorria desde la parte inferior a la superior, se ancló al aparato lumínico. Luego se definió un recorrido de 1.2 mt. con dirección 1 y -1, por lo que la fuente de luz baja y sube.
[Esta es una imagen](600px-Mecanismo_tela_hilos_mva.jpg)

- Arduino

[Códigos para arduino y los distintos elementos utilizados](ino/README.md)


## Construcción Totem

Construcción de estructura con listones de 20x20 de pino oregón. Se cortan 4 listones de 2 mt. cada uno. se cortan 8 listones de 30 cm, Se ensamblan con pistola de grapas neumática segun disposición del modelo 3D.
Luego se procede a la contrucción y posicionamiento del mecanismo superior en acrílico cortado por laser cnc.
Seguido se instaló el riel vertical (tubo de conduit de 20 mm.). en conjunto se construyó el aparato lumínico disponiendo cuatro tiras LED por 4 de las caras del paralelógramo.
Luego se instalaron las telas de velo, y se colocaror y cosieron los hilos a estas.
Posteriormente se instalaron los pulsadores en las cuatro caras.
una vez aquí, se pegaron las membranas de papel diamante en el exterior del totem.
Finalmente se conectaron todos los componentes electronicos y se ubicaron en la parte inferior del tótem.



![Esta es una imagen](800px-Totem_escala_real_terminado.jpg)
![Esta es una imagen]()
/cad
/cam
## Estructura de carpetas
## Herramientas y tecnologías utilizadas

