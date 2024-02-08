import PIL.Image, PIL.ImageTk
import tkinter
from tkinter import ttk
from tkinter import*
import os
from tkintermapview import TkinterMapView

# create tkinter window
root_tk = tkinter.Tk()
root_tk.geometry(f"{1000}x{1000}")
root_tk.title("Safety.net")
root_tk.iconbitmap('c:/Users/s15lo/newhacks/fish.ico')

my_frame = LabelFrame(root_tk, font=("Courier", 18))
my_frame.pack(padx = 30, pady=10)

# create map widget
map_widget = TkinterMapView(root_tk, width=40, height=100, corner_radius=0)
map_widget.pack(side = RIGHT, padx = 0, pady= 0)

def lookup():
    map_widget.set_address(my_entry.get())

map_widget.pack()



# Create a Label Widget to display the text or Image

Label1 = Label(root_tk, text="IMPORTANT INFORMATION: \n\n\n", width = 30, height= 400, font=('Courier 12 bold'), background="#FFE4C4", foreground="black", borderwidth=10, relief="solid")
Label1.pack(pady=0, padx=0)

my_entry = Entry(my_frame, font=("Courier", 12))
my_entry.grid(row=0, column=1, pady=0, padx=0)

my_button = Button(my_frame, text="   Search  ", font=("Courier", 18), command=lookup)
my_button.grid( row=0, column=10, padx=20)

def polygon_click(polygon):
    print(f"{polygon.name}")

polygon_1 = map_widget.set_polygon([(43.7571324, -79.5173560),
                                    (43.7211418, -79.5087729),
                                    (43.7375158,-79.4345272),
                                    (43.7730173, -79.4438827)],
                                   fill_color= 'orange',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_2 = map_widget.set_polygon([(43.6280781, -79.4047402),
                                    (43.6342284, -79.3952129),
                                    (43.6445396, -79.3600783),
                                    (43.6614311, -79.3152320),
                                    (43.6505018, -79.3099963),
                                    (43.6173091, -79.3178928),
                                    (43.6105978, -79.3446719),
                                    (43.6103492, -79.3920505)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_3 = map_widget.set_polygon([(43.6748033, -79.6789024),
                                    (43.6571703, -79.6558997),
                                    (43.6517055 ,-79.6191642),
                                    (43.6628830, -79.5951316),
                                    (43.6718235, -79.5875785),
                                    (43.6844868, -79.5927283),
                                    (43.7055865, -79.6280906),
                                    (43.6944170, -79.6613929)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_4 = map_widget.set_polygon([(43.7850819, -79.3411494),
                                    (43.7766541, -79.3541957),
                                    (43.7664896, -79.3651820),
                                    (43.7526036, -79.3565989),
                                    (43.7454113, -79.3322230),
                                    (43.7555794, -79.3030406),
                                    (43.7734314, -79.2903377),
                                    (43.7858254, -79.3129970)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_5 = map_widget.set_polygon([(43.6402534, -79.5434545),
                                    (43.6347576, -79.5432337),
                                    (43.6285142, -79.5366247),
                                    (43.6322417, -79.5242651),
                                    (43.6408140, -79.5262392),
                                    (43.6434849, -79.5264967)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_6 = map_widget.set_polygon([(43.6474755, -79.3815078),
                                    (43.6457985, -79.3845977),
                                    (43.6418234, -79.3847693),
                                    (43.6407675, -79.3810786),
                                    (43.6413265, -79.3778171),
                                    (43.6462644, -79.3752421)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_7 = map_widget.set_polygon([(43.6546761, -79.3876223),
                                    (43.6511440, -79.3862383),
                                    (43.6524249, -79.3803265),
                                    (43.6559965, -79.3812805)],
                                   fill_color= 'red',
                                   
                                    outline_color="black",
                                    border_width=1,
                                   command = polygon_click,
                                   name = "not safe" )

polygon_8 = map_widget.set_polygon([(43.7218868, -79.4095062),
                                    (43.6923532, -79.4028114),
                                    (43.6998001, -79.3871903),
                                    (43.7226312, -79.3949150)],
                                   fill_color= 'red',

                                    outline_color="black",
                                    border_width=1,
                                   #command = polygon_click,
                                   name = "not safe" )

polygon_7QUEENSPARK = map_widget.set_polygon([(43.6606718, -79.3908063),
                                    (43.6631089, -79.3931881),
                                    (43.6660426, -79.3927590),
                                    (43.6636367, -79.3905488)],
                                   fill_color= 'orange',

                                    outline_color="black",
                                    border_width=1,
                                   #command = polygon_click,
                                   name = "not safe" )


polygon_7QUEENSPARK = map_widget.set_polygon([(43.6421368, -79.3909265),
                                    (43.6433325, -79.3896391),
                                    (43.6427114, -79.3881370),
                                    (43.6419971, -79.3875577),
                                    (43.6407548, -79.3882443),
                                    (43.6411275, -79.3906476)
                                    ],
                                   fill_color= 'orange',

                                    outline_color="black",
                                    border_width=1,
                                   #command = polygon_click,
                                   name = "not safe" )

class data:
  def __init__(self, information):
    self.information = information



uoft = data("IMPORTANT INFORMATION:\n\n\n University of Toronto \n Post-Secondary School \n SAFE Location \n 27 King's College Cir,\n Toronto, ON Canada")
mount_sinai = data("IMPORTANT INFORMATION:\n\n\n Mount Sinai Hosptial \n Hospital \n SAFE Location \n 600 University Ave,\n Toronto, ON Canada")
st_mikes = data("IMPORTANT INFORMATION:\n\n\n St Michaels Hospital \n Hospital \n SAFE \n 36 Queen St E,\n Toronto, ON, Canada")
north_york_hospital = data("IMPORTANT INFORMATION:\n\n\n North York General\n Hospital\n NOT SAFE\n 4001 Leslie St,\n Toronto, ON, Canada")
marcs_nofrills = data("IMPORTANT INFORMATION:\n\n\n NoFrills\n Grocery Store\n SAFE\n 925 Rathburn Rd E,\n Mississauga, ON Canada")
loblaws = data("IMPORTANT INFORMATION:\n\n\n Loblaws\n Grocery Store\n SAFE\n 585 Queen St W,\n Toronto, ON, Canada")
metro = data("IMPORTANT INFORMATION:\\n\n\n Metro\n Grocery Store\n SAFE\n 80 Front St E,\n Toronto, ON, Canada")
hillcrest  =data("IMPORTANT INFORMATION:\n\n\n Hillcrest Community School\n Elementary School\n SAFE\n 44 Hilton Ave,\n Toronto, ON, Canada")
sheppard = data("IMPORTANT INFORMATION:\n\n\n Sheppard Public School\n Elementary School\n UNVERIFIED\n 430 Sheppard Ave W,\n North York, ON, Canada")
airport = data("IMPORTANT INFORMATION:\n\n\n Toronto Pearson Airport\n Airport\n UNSAFE\n 6301 Silver Dart Dr,\n Mississauga, Canada")



def function1(marker_1):
    Label1["text"] = marker_1.text
    Label1["text"] = uoft.information
    Label1["background"] = "#77DD77"

def function2(marker_2):
    Label1["text"] = marker_2.text
    Label1["text"] = mount_sinai.information
    Label1["background"] = "#77DD77"

def function3(marker_3):
    Label1["text"] = marker_3.text
    Label1["text"] = st_mikes.information
    Label1["background"] = "#77DD77"

def function4(marker_4):
    Label1["text"] = marker_4.text
    Label1["text"] = north_york_hospital.information
    Label1["background"] = "#FF474C"

def function5(marker_5):
    Label1["text"] = marker_5.text
    Label1["text"] = marcs_nofrills.information
    Label1["background"] = "#77DD77"

def function6(marker_6):
    Label1["text"] = marker_6.text
    Label1["text"] = loblaws.information
    Label1["background"] = "#77DD77"

def function7(marker_7):
    Label1["text"] = marker_7.text
    Label1["text"] = metro.information
    Label1["background"] = "#77DD77"

def function8(marker_8):
    Label1["text"] = marker_8.text
    Label1["text"] = hillcrest.information
    Label1["background"] = "#77DD77"

def function9(marker_9):
    Label1["text"] = marker_9.text
    Label1["text"] = sheppard.information
    Label1["background"] = "#FDFD96"

def function10(marker_10):
    Label1["text"] = marker_10.text
    Label1["text"] = airport.information
    Label1["background"] = "#FF474C"




#hospital pins
red_pin = PIL.ImageTk.PhotoImage(PIL.Image.open(os.path.join("c:/Users/s15lo/NewHacks/google_maps_pin.png")).resize((20, 30)))
#school pins
blue_pin = PIL.ImageTk.PhotoImage(PIL.Image.open(os.path.join("c:/Users/s15lo/NewHacks/blue_pin.png")).resize((20, 30)))
#grocery store pins
green_pin = PIL.ImageTk.PhotoImage(PIL.Image.open(os.path.join("c:/Users/s15lo/NewHacks/green_pin.png")).resize((20, 30)))
#airport pins
black_pin = PIL.ImageTk.PhotoImage(PIL.Image.open(os.path.join("c:/Users/s15lo/NewHacks/black_pin.png")).resize((20, 30)))

#uoft
marker_1 = map_widget.set_marker(43.6634, -79.3960, icon = blue_pin, text = " ", command = function1)

#mount sinai
marker_2 = map_widget.set_marker(43.6574, -79.3903, icon = red_pin, text = " ", command = function2)

#st mikes hospital
marker_3 = map_widget.set_marker(43.6528, -79.3763, icon = red_pin, text = " ", command = function3)

#north york general hospital
marker_4 = map_widget.set_marker(43.7688, -79.3627, icon = red_pin, text = " ", command = function4)

#marcs nofrills
marker_5 = map_widget.set_marker(43.616288389408965, -79.61783111364495, icon = green_pin, text = " ", command = function5)

#loblaws
marker_6 = map_widget.set_marker(43.64790439812722, -79.40156563212292, icon = green_pin, text = " ", command = function6)

#metro
marker_7 = map_widget.set_marker(43.64935087092325, -79.37272377630252, icon = green_pin, text = " ", command = function7)

#hillcrest
marker_8 = map_widget.set_marker(43.67930347522561, -79.41570783820553, icon = blue_pin, text = " ", command = function8)

#sheppard
marker_9 = map_widget.set_marker(43.745194333814915, -79.48835934745841, icon = blue_pin, text = " ", command = function9)

#sheppard
marker_10 = map_widget.set_marker(43.6817, -79.6145, icon = black_pin, text = " ", command = function10)

map_widget.set_address("27 King's College Cir, Toronto, ON, Canada")
map_widget.set_zoom(12)


map_widget.pack(fill="both", expand=True)

root_tk.mainloop()

