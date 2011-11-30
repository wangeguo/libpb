HTML = index.html concepts.html reference.html
IMG = generator_flow.png

all: $(HTML) $(IMG) 

%.png: %.svg
	rsvg $< $@

%.html: %.rst
	rst2html --stylesheet=lsr.css --link-stylesheet $< $@

clean:
	-rm -f $(HTML) $(IMG)
