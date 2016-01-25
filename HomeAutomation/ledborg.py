# AARTHY SUNDARAM (EDM12B002), KAVIYA.R (EDM12B015)
# web.py : controlling your pi from a smartphone

import web 
from web import form

urls = ('/', 'index') 
render = web.template.render('templates')

app= web.application(urls,globals())
my_form=form.Form( 
	form.Button("btn", id="btnR", value="R", html= "Red", class_="btnRed"),
	form.Button("btn", id="btnG", value="G", html= "Green", class_="btnGreen"),
	form.Button("btn", id="btnO", value="O", html= "-Off-", class_="btnOff")
	
	)
	
class index:
	def GET(self):
		form=my_form()
		return render.index(form, "Raspberry Pi Python Remote Control")
		
	def POST(self):
		userData= web.input()
		
		if userData.btn == "R":
			print "RED"
			lbColour = "200"
		elif userData.btn == "G":
			print "GREEN"
			lbColor="020"
	elif userData.btn == "O":
			lbColor="000"
			print "Turn LedBorg Off" 
	else:
		print "Do nothing else- assume something fishy is going on...."
		
		LedBorg= open('/dev/ledborg', 'w')
		LedBorg.write(lbColour)
		print lbColour
		del LedBorg 
		
		raise web.seeother('/')
		
if_name_== '_main_': 
	app.run()
			
			raise