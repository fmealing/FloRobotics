import tkinter as tk
import tkinter.messagebox


class CalculatorButton(tk.Button):
    """A button with callback, to be used with a CalculatorGrid widget."""

    def __init__(self, master, callback=None, **kwargs):
        """
        Initializes the button with the given callback function.

        :param master: The parent widget.
        :param callback: The function to call when the button is clicked.
        :param kwargs: Additional keyword arguments for the button.
        """
        self.callback = callback
        super().__init__(master, **kwargs)
        self.config(command=self.on_click)

    def on_click(self):
        """Handles button click events by invoking the callback with the button's text."""
        if self.callback:
            self.callback(self['text'])


class CalculatorGrid(tk.Frame):
    """A tkinter Frame that displays buttons and implements a simple calculator."""

    keys = [
        [("C", 1), ("CE", 1)],
        [("7", 1), ("8", 1), ("9", 1), ("+", 1)],
        [("4", 1), ("5", 1), ("6", 1), ("-", 1)],
        [("1", 1), ("2", 1), ("3", 1), ("*", 1)],
        [("0", 1), ("=", 2), ("/", 1)],
    ]

    def __init__(self, master, **kwargs):
        """
        Initializes the calculator grid.

        :param master: The parent widget.
        :param kwargs: Additional keyword arguments for the frame.
        """
        super().__init__(master, **kwargs)

        max_columns = max(len(row) for row in CalculatorGrid.keys)
        self.result = tk.Entry(self)
        self.result.grid(row=0, column=0, columnspan=max_columns, sticky="nsew")

        # Add the buttons
        keypad = tk.Frame(self)
        keypad.grid(row=1, column=0, sticky="nsew")

        row = 0
        for key_row in CalculatorGrid.keys:
            col = 0
            for key in key_row:
                btn = CalculatorButton(keypad, text=key[0], width=2, callback=self.on_click)
                btn.grid(row=row, column=col, columnspan=key[1], sticky="nsew")
                col += key[1]
            row += 1

    def on_click(self, char: str):
        """Called by a CalculatorButton when it's clicked."""
        if char == "=":
            self.calculate_result()
        elif char == "C":
            self.clear_result()
        elif char == "CE":
            self.clear_last_entry()
        else:
            self.append_to_result(char)

    def calculate_result(self):
        """Evaluates the expression in the result entry and displays the result."""
        try:
            expression = self.result.get()
            answer = str(eval(expression))
        except (SyntaxError, ZeroDivisionError) as e:
            tk.messagebox.showerror("Error", str(e))
        else:
            self.result.delete(0, tk.END)
            self.result.insert(0, answer)

    def clear_result(self):
        """Clears the entire result entry."""
        self.result.delete(0, tk.END)

    def clear_last_entry(self):
        """Clears the last character in the result entry."""
        self.result.delete(len(self.result.get()) - 1, tk.END)

    def append_to_result(self, char: str):
        """Appends a character to the result entry."""
        self.result.insert(tk.END, char)


def main():
    """Main function to run the calculator application."""
    main_window_padding = 9

    main_window = tk.Tk()
    main_window.title("Calculator")
    main_window.geometry("640x480")
    main_window['padx'] = main_window_padding

    calc = CalculatorGrid(main_window)
    calc.grid(row=1, column=0, sticky="nsew")

    main_window.mainloop()


if __name__ == "__main__":
    main()
