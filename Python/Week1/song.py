class Song:
    """
    Class to represent a song

    Attributes:
        title (str): The title of the song
        artist (Artist): An artist object representing the songs creator
        duration (int): The duration of the song in seconds. May be zero
    """

    def __init__(self, title, artist, duration):
        self.title = title
        self.artist = artist
        self.duration = duration


# help(Song.__init__)
# print(Song.__doc__)
# print(Song.__init__.__doc__)
# Song.__init__.__doc__ = """
#         Song init method
#
#         :param title: Initialises the 'title' attribute
#         :param artist: At artist object representing the song's creator
#         :param duration: Initial value for the 'duration' attribute
#         """
# help(Song)

class Album:
    """ Class to represent a album, using its tracklist

    Attributes:
        album_name (str): The name of the album
        year (int): The year the album was released
        atrist (Artist): hew artist responsible to  the album.
            If not specified, the artist will default to an artist with the name
            "Various Artists".
        tracks (List[Song]): A list of the songs on the album.

    Methods:
        addSong: Used to add a new song to the album's track list.
        """

    def __init__(self, name, year, artist=None):
        self.name = name
        self.year = year
        if artist is None:
            self.artist = artist("Various Artists")
        else:
            self.artist = artist

        self.tracks = []

    def add_song(self, song, position=None):
        """Adds a song to the track list

        Arguments:
            song (Song): a song to add
            position (Optional[int]): If specified, the song will be added to that position
                in the track list - inserting it between other songs if necessary.
                Otherwise, the song will be added to the end of the list.
        """
        if position is None:
            self.tracks.append(song)
        else:
            self.tracks.insert(position, song)
