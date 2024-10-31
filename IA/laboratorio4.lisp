;;;; laboratorio4.lisp
;;;; Disciplina de IA
;;;; Laboratorio sobre funcoes recursivas e boas praticas de programacao em Lisp



;;; Exercicio Introdutorio.
;; comprimento de uma lista
(defun comprimento(lista)
"Recebe uma lista e retorna um valor inteiro que indica quantos elementos existem nesta lista"
  (cond
    ((null lista) 0)
    (t (1+ (comprimento (cdr lista))))
    )
  )
;; tamanho-das-sublistas
(defun tamanho-das-sublistas (lista)
"Recebe uma lista constituida por sublistas e retorna uma lista com valores inteiros que indicadam o comprimento das respetivas sublistas"
  (cond 
    ((null lista) nil)
    (T (cons (comprimento (car lista)) (tamanho-das-sublistas (cdr lista))))
  )
)

;;; Exercicio sobre funcoes recursivas

;; factorial
(defun factorial (n)
  (cond ((= n 1) 1)
        (t (* n (factorial (- n 1))))
  )
)

;; n-esimo
(defun n-esimo (n lst)
  (cond ((<= n 0) (first lst))
        (t (n-esimo (- n 1) (cdr lst)))
  )
)

;; soma-lista
(defun soma-lista (lst)
  (cond ((null lst) 0)
        (t (+ (first lst) (soma-lista (cdr lst))))
  )
)

;; existe
(defun existe (n lst)
  (cond ((= n (first lst)) lst)
        (t (existe n (cdr lst)))
  )
)

;; junta
(defun junta (lst1 lst2)
  (cond ((null lst1) lst2)
        (t (cons (car lst1) (junta (cdr lst1) lst2)))
  )
)


;; inverte
(defun inverte (lst)
  (cond ((null lst) NIL)
        (t (append (inverte (cdr lst)) (list (car lst))))
  )
)

;; conta-atomos
(defun conta-atomos (lst)
  (cond
    ;; Se a lista está vazia, retorna 0
    ((null lst) 0)
    ;; Se o primeiro elemento é uma lista, chama recursivamente para contar os átomos dentro dela
    ((listp (car lst)) (+ (conta-atomos (car lst)) (conta-atomos (cdr lst))))
    ;; Se o primeiro elemento é um átomo, conta 1 e continua com o resto da lista
    (t (+ 1 (conta-atomos (cdr lst))))))



;; alisa
(defun alisa (lst)
  (cond
    ;; Se a lista está vazia, retorna uma lista vazia
    ((null lst) nil)
    ;; Se o primeiro elemento é uma lista, chama recursivamente para achatar essa sublista
    ((listp (car lst)) (append (alisa (car lst)) (alisa (cdr lst))))
    ;; Se o primeiro elemento é um átomo, adiciona-o à lista achatada
    (t (cons (car lst) (alisa (cdr lst))))))
