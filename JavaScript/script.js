document.addEventListener("DOMContentLoaded", () => {
  // Dynamic Skills Sorting
  const sortSkillsDropdown = document.getElementById("sort-skills-dropdown");
  const skillsList = document.getElementById("skills-list");

  const getProficiencyLevel = (text) => {
    const levels = {
      1: "Beginner",
      2: "Beginner/Intermediate",
      3: "Intermediate",
      4: "Intermediate/Advanced",
      5: "Advanced",
    };
    const levelText = text.split(" - ")[1];
    return Object.keys(levels).find((key) => levels[key] === levelText) || 0;
  };

  sortSkillsDropdown.addEventListener("change", () => {
    const sortOrder = sortSkillsDropdown.value;
    const skills = Array.from(skillsList.getElementsByTagName("li"));

    skills.sort((a, b) => {
      const levelA = getProficiencyLevel(a.textContent);
      const levelB = getProficiencyLevel(b.textContent);
      return sortOrder === "asc" ? levelA - levelB : levelB - levelA; // Sort based on selected order
    });

    // Clear the current list and append sorted items
    skillsList.innerHTML = "";
    skills.forEach((skill) => {
      skillsList.appendChild(skill);
    });
  });

  // Dynamic Projects Sorting
  const sortProjectsDropdown = document.getElementById(
    "sort-projects-dropdown"
  );
  const projectsList = document.getElementById("projects-list");

  sortProjectsDropdown.addEventListener("change", () => {
    const sortOrder = sortProjectsDropdown.value;
    const projects = Array.from(projectsList.getElementsByTagName("li"));

    projects.sort((a, b) => {
      const textA = a.textContent.toUpperCase();
      const textB = b.textContent.toUpperCase();
      if (sortOrder === "asc") {
        return textA < textB ? -1 : textA > textB ? 1 : 0;
      } else {
        return textA > textB ? -1 : textA < textB ? 1 : 0;
      }
    });

    // Clear the current list and append sorted items
    projectsList.innerHTML = "";
    projects.forEach((project) => {
      projectsList.appendChild(project);
    });
  });
});
