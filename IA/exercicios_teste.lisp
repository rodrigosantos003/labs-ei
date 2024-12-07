(defun metodo-bisseccao (fun a b tolerancia)
  (if (< (- b a) tolerancia)(/ (+ a b) 2)
      (let* ((c (/ (+ a b) 2))
             (fa (funcall fun a))
             (fc (funcall fun c)))
        (cond
            ((= fc 0) c)
            ((< (* fa fc) 0) (metodo-bissecao fun c b tolerancia))
            (t (metodo-bissecao fun a c tolerancia)))))
)

(defun f (x)
  (- (* x x) 4)) 