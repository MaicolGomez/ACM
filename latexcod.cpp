\documentclass[a4paper]{article}

\usepackage[english]{babel}
\usepackage[utf8]{inputenc}
\usepackage{amsmath}
\usepackage{graphicx}
\usepackage[colorinlistoftodos]{todonotes}
\usepackage{amsfonts}
\usepackage[a4paper,top=3.3cm,bottom=3.8cm,
inner=3.21cm,outer=3.21cm,bindingoffset=0.5cm]{geometry} % margens

\title{Formulación del TRNDP}

\author{Maicol Gomez, Jorge Antunez de Mayolo y Walter Barrientos}

\date{\today}

\begin{document}
\maketitle

\section{Datos}

\begin{itemize}
\item $N$ Numero de zonas o vértices
\item $E$ Numero de aristas o links
\item $D_{i,j}$ Matriz de demanda de viajes de zona $i$ a $j$
\item $L_{min}$ Distancia minima entre paraderos
\item $L_{max}$ Distancia maxima entre paraderos
\item $CAP$ Capacidad de aisentos de los buses
\item $R_{min}$ Distancia minima de cualquier ruta
\item $R_{max}$ Distancia maxima de cualquier ruta
\item $e_{i,j}$ Conjunto de aristas que conponen el grafo
\item $P$\% Porcentaje minimo de la demanda de viajes satisfecha
\item $Cv_{1}$ Costo unitario por hora por demanda instatisfecha
\item $Cv_{2}$ Costo de penalización por cada viaje realizado con transferencia
\item $M_{max}$ Número máximo de Rutas por vía
\item $C1,\:\:C2\:\:y\:\:C3$ Son introducidos para reflejar la importancia de cada parte de la función objetivo
\end{itemize}

\section{Variables de Decisión}

\begin{itemize}
\item $m$ Número de rutas
\item $D^d_{i,j,k}$ Matriz de demanda de viajes satisfechos de la zona $i$ a la zona $j$ por medio de la ruta $k$ de forma directa
\item $D^I_{i,j,k}$ Matriz de demanda de viajes satisfechos de la zona $i$ a la zona $j$ por medio de la ruta $k$ de forma indirecta (1 Transferencia)
\item $T^d_{i,j,k}$ Matriz de costos por viaje satisfecho de la zona $i$ a la zona $j$ por medio de la ruta $k$ de forma indirecta (1 Transferencia)
\item $T^I_{i,j,k}$ Matriz de costos por viaje satisfecho de la zona $i$ a la zona $j$ por medio de la ruta $k$ de forma indirecta (1 Transferencia)
\item Para las matrices de costos ($T^d_{i,j,k}$ y $T^I_{i,j,k}$) se tomara en cuenta el costo de espera, viaje y transferencia expresado en unidades monetarias.
\item $\forall \: p \: \in \: m$ aristas que lo conforman, es decir $p \: = \{ e_{x_{1},x_{2}} \: , \: e_{x_{2},x_{3}} \: \cdots \: e_{x_{size-1},x_{size}} \}$ , tal que $size$ es la cantidad de aristas de la ruta $p$
\item $s^p_{pos_{(1,size})}$ Posición de paraderos para cada ruta
\item $M_{e,k}$ Matriz de aristas usadas $e$ para cada ruta $k$: 0(No usada) , 1(Usada)
\end{itemize}



\section{Función Objetivo}
\begin{eqnarray*}\label{eq:mincx}
min\,z = \,\,\,  C1(\sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^d_{i,j,k}T^d_{i,j,k}\,\,+\,\,\sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^I_{i,j,k}T^I_{i,j,k})\,\,\,\,+\\ 
C2\cdot Cv_{1}(\sum_{ i \in N }\sum_{j \in N}D_{i,j}\,\,-\,\, \sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^d_{i,j,k}\,\,\,\, - \,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\,\, \\ \sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^I_{i,j,k})\,\,\,\,+\,\,\,\,
C3\cdot Cv_{2}\sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^I_{i,j,k}\,\,\,\,\,\,\,\,\,\,\,
\end{eqnarray*}

sujeto a:
\begin{eqnarray*}\displaystyle
\forall\: p \in m :\:\: R_{min} \leq \: \sum^{size}_{i = 1}e^p_{i} \leq \: R_{max} \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\\
  (\sum_{ i \in N }\sum_{j \in N}D_{i,j})P\%\le \sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^d_{i,j,k} + \sum_{ i \in N }\sum_{j \in N}\sum_{ k \in R }D^I_{i,j,k}\\
\forall \: p \in m \: : L_{min} \le \forall\:i \in ruta_{p}\:\:distancia(s_{i+1} - s_{i}) \le L_{max}\\
\forall \:\: e \in E \:\:\: \sum_{p \in m} \le  M_{max} \:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:\:
\end{eqnarray*}

El primer termino de la función objetivo representa el costo de usarios tanto directo como con una tranferencia, el segundo representa el costo de la demanda insatisfecha y el ultimo termino es la penalización al uso de viajes realizados con transferencia.
\\
La primera restricción hace referencia a la distancia maxima y minima de cada ruta encontrada.\\
La segunda restricción hace referencia al porcentaje minimo de demanda satisfecha.\\
La tercera restricción hace refenrecia a la distancia maxima y minima entre cada paradero de cada ruta.\\
La cuarta restricción hace refenrecia a la cantidad de rutas maximas por cada vía(arista).


\end{document}
